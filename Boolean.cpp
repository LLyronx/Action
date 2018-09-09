#include <iostream>
#include "Boolean.h"
#include "String.h"

namespace Action
{
    const Boolean Boolean::True = Boolean (true);
    const Boolean Boolean::False = Boolean (false);
    String Boolean::get_name() const
    {
        return "Action::Boolean";
    }
    String Boolean::to_string() const
    {
        if (get_val() )
            return "True";
        else
            return "False";
    }
}
