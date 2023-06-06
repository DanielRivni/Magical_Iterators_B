#include "MagicalContainer.hpp"
#include <algorithm>

using namespace std;

namespace ariel
{
    void MagicalContainer::SideCrossIterator::initIndexes()
    {
        int end = container.size() / 2;
        if (container.size() % 2 != 0)
        {
            end++;
        }
        for (unsigned long i = 0; i < end; i++)
        {
            indexes.push_back(i);

            if (i != ((unsigned long)container.size() - 1 - i))
            {
                indexes.push_back(((unsigned long)container.size() - 1 - i));
            }
        }
    }

    // constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container)
        : container(container), index(0)
    {
        initIndexes();
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container, unsigned long index)
        : container(container), index(index)
    {
        initIndexes();
    }

    // copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : container(other.container), index(other.index)
    {
        initIndexes();
    }

    // destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // move constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) noexcept
        : container(other.container), index(other.index) {}

    // move assignment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
    {
        if (this != &other)
        {
            index = other.index;
            indexes = other.indexes;
        }
        return *this;
    }

    // copy assignment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
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
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return &container == &other.container && index == other.index;
    }

    // Inequality comparison
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return index != other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return index > other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return index < other.index;
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const
    {

        return container.elements[indexes[index]];
    }

    // Pre-increment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (index >= indexes.size())
        {
            throw std::runtime_error("Can't increment beyond the end");
        }
        ++index;

        return *this;
    }

    // begin
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator(container);
    }

    // end
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return SideCrossIterator(container, indexes.size());
    }

}
