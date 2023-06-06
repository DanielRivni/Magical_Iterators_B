#include "MagicalContainer.hpp"
#include <algorithm>
using namespace std;
namespace ariel
{

    void MagicalContainer::AscendingIterator::initIndexes()
    {
        indexes.resize((unsigned long)container.size());
        for (unsigned long i = 0; i < container.size(); ++i)
        {
            indexes[i] = i;
        }
        sort(indexes.begin(), indexes.end(), [this](unsigned long i, unsigned long j)
             { return container.elements[i] < container.elements[j]; });
    }

    // constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container)
        : container(container), index(0)
    {
        initIndexes();
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container, unsigned long index)
        : container(container), index(index)
    {
        initIndexes();
    }

    // copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), index(other.index)
    {
        initIndexes();
    }

    // destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // move constructor
    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) noexcept
        : container(other.container), index(other.index) {}

    // move assignment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
    {
        if (this != &other)
        {
            index = other.index;
            indexes = other.indexes;
        }
        return *this;
    }

    // copy assignment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
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
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return &container == &other.container && index == other.index;
    }

    // Inequality comparison
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return index != other.index;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return index > other.index;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return index < other.index;
    }

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const
    {
        return container.elements[indexes[index]];
    }

    // Pre-increment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (index >= indexes.size())
        {
            throw std::runtime_error("Can't increment beyond the end");
        }
        ++index;

        return *this;
    }

    // begin
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator(container);
    }

    // end
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return AscendingIterator(container, indexes.size());
    }
}
