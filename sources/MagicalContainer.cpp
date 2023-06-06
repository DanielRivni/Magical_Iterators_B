#include "MagicalContainer.hpp"
#include <cassert>

using namespace std;

namespace ariel
{
    void MagicalContainer::addElement(int element)
    {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element)
    {
        auto it = find(elements.begin(), elements.end(), element);
        if (it == elements.end())
        {
            throw std::runtime_error("Element not found in the container");
        }
        elements.erase(it);
    }

    int MagicalContainer::size() const
    {
        return elements.size();
    }

    int &MagicalContainer::operator[](int index)
    {
        assert((index >= 0) && (index < elements.size()));
        return elements[(unsigned long)index];
    }
    bool MagicalContainer::operator!=(const MagicalContainer &other) const
    {
        return elements != other.elements;
    }

}
