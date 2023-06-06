#include "MagicalContainer.hpp"
#include <cmath>
#include <algorithm>

using namespace std;
namespace ariel
{

    // basic Prime function
    bool MagicalContainer::PrimeIterator::isPrime(int n) const
    {
        if (n <= 1)
        {
            return false;
        }
        int limit = std::sqrt(n);
        for (int i = 2; i <= limit; ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    void MagicalContainer::PrimeIterator::initIndexes()
    {
        for (unsigned long i = 0; i < container.size(); i++)
        {
            if (isPrime(container.elements[i]))
            {
                indexes.push_back(i);
            }
        }
    }
    // constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container)
        : container(container), index(0)
    {
        initIndexes();
    }
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container, unsigned long index)
        : container(container), index(index)
    {
        initIndexes();
    }

    // copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : container(other.container), index(other.index)
    {
        initIndexes();
    }

    // destructor
    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    // move constructor
    MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other) noexcept
        : container(other.container), index(other.index)
    {
        initIndexes();
    }

    // move assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
    {
        if (this != &other)
        {
            index = other.index;
            indexes = other.indexes;
        }
        return *this;
    }

    // copy assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (container != other.container)
        {
            throw std::runtime_error("iterators are pointing at different containers");
        }
        if (this != &other)
        {
            index = other.index;
            indexes = other.indexes;
        }
        return *this;
    }

    // Equality comparison
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return &container == &other.container && index == other.index;
    }

    // Inequality comparison
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return index != other.index;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return index > other.index;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return index < other.index;
    }

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const
    {
        return container.elements[indexes[index]];
    }

    // Pre-increment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (index >= indexes.size())
        {
            throw std::runtime_error("Can't increment beyond the end");
        }
        ++index;

        return *this;
    }

    // begin
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return PrimeIterator(container);
    }

    // end
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return PrimeIterator(container, indexes.size());
    }
}
