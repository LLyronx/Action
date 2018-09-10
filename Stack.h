#include <iostream>
#include "ArrayList.hpp"
#include "Integer.h"
#include "Type_NotCorrespond.h"

/*
    想去了解你
    了解你光芒以外的地方
*/

#ifndef Action__Stack
#define Action__Stack
namespace Action
{
    template <class T>
    class Stack: public Object
    {
        private:
            ArrayList<T> m_array;
        public:
            Stack() {}
            Stack (const Stack & another) : m_array (another.m_array) {}
            Stack & operator = (const Stack &);

            virtual void push (const T &);
            virtual T pop();
            virtual T top() const ;
            virtual void clear()
            {
                m_array.clear();
            }
            virtual Boolean empty() const
            {
                return m_array.empty();
            }
            virtual Integer size() const
            {
                return m_array.size();
            }
            virtual Boolean operator == (const Object & another_one)
            {
                try
                {
                    const Stack<T> & another_stack = dynamic_cast<const Stack<T> &> (another_one);
                    return m_array == another_stack.m_array;
                }
                catch (std::bad_cast)
                {
                    throw Type_NotCorrespond();
                }
            }
            virtual String get_name() const override
            {
                return "Action::Stack";
            }
            virtual String to_string() const override
            {
                return m_array.to_string();
            }
            virtual ~Stack() {}
    };
}
#endif /* Action__Stack */

