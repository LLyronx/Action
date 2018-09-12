#include <iostream>
#include "Object.h"
#include "LinkedList.hpp"
#include "Integer.h"
#include "Real.h"
#include "Boolean.h"
#include "String.h"
#include "ArrayList.hpp"
#include "Set_PtrOutOfRange.h"
#include "Set_ElementNotExists.h"

/*
    你怅惘的脸萦绕我的梦境
    雨打湿夜的风铃。
*/

#ifndef Action__HashSet
#define Action__HashSet
namespace Action
{
    template <class T>
    class HashSet: public Object
    {
        public:
            struct Pointer
            {
                private:
                    const HashSet * m_set;
                    typename LinkedList<T>::Pointer m_ptr;
                public:
                    Pointer(const HashSet * set, typename LinkedList<T>::Pointer ptr) :
                        m_set(set), m_ptr(ptr) {}
                    T & operator *()
                    {
                        if(*this == m_set->end())
                            throw Set_PtrOutOfRange();
                        else
                            return *m_ptr;
                    }
                    T * operator ->()
                    {
                        return & (*this);
                    }
                    Pointer & operator ++()
                    {
                        *this = next();
                        return *this;
                    }
                    Pointer & operator --()
                    {
                        *this = last();
                        return *this;
                    }
                    Pointer operator ++ (int)
                    {
                        Pointer ptrReturnVal(*this);
                        *this = next();
                        return ptrReturnVal;
                    }
                    Pointer operator -- (int)
                    {
                        Pointer ptrReturnVal(*this);
                        *this = last();
                        return ptrReturnVal;
                    }

                    Pointer next() const
                    {
                        if(*this == m_set->end())
                            throw Set_PtrOutOfRange();
                        else if(*this == m_set->v_end())
                            return m_set->end();
                        else if(*this == m_set->v_begin())
                            return m_set->begin();
                        else
                        {
                            if(m_ptr.next() != (m_ptr.get_list())->end())
                                return Pointer(m_set, m_ptr.next());
                            else
                            {
                                LinkedList<T> * next_valid_list;
                                for(next_valid_list = m_ptr.get_list() + 1; next_valid_list < m_set->m_links + m_set->m_link_capacity; ++next_valid_list)
                                    if(next_valid_list->size() > 0)
                                        break;
                                if(next_valid_list >= m_set->m_links + m_set->m_link_capacity)
                                    return m_set->end();
                                else
                                    return Pointer(m_set, next_valid_list->begin());
                            }
                        }
                    }
                    Pointer last() const
                    {
                        if(*this == m_set->v_begin())
                            throw Set_PtrOutOfRange();
                        else if(*this == m_set->begin())
                            return m_set->v_begin();
                        else if(*this == m_set->end())
                            return m_set->v_end();
                        else
                        {
                            if(m_ptr.last() != (m_ptr.get_list())->v_begin())
                                return Pointer(m_set, m_ptr.last());
                            else
                            {
                                LinkedList<T> * last_valid_list;
                                for(last_valid_list = m_ptr.get_list() - 1; last_valid_list >= m_set->m_links; --last_valid_list)
                                    if(last_valid_list->size() > 0)
                                        break;
                                if(last_valid_list < m_set->m_links)
                                    return m_set->v_begin();
                                else
                                    return Pointer(m_set, last_valid_list->v_end());
                            }
                        }
                    }
                    Boolean operator == (const Pointer & another_pointer) const
                    {
                        return Boolean(m_ptr == another_pointer.m_ptr && m_set == another_pointer.m_set);
                    }
                    Boolean operator != (const Pointer & another_pointer) const
                    {
                        return NOT operator == (another_pointer);
                    }
            };
            friend struct Pointer;
        public:
            HashSet();
            HashSet(const HashSet &);
            HashSet & operator = (const HashSet &);
            virtual void insert(const T &);
            virtual void erase(const T &);
            virtual Boolean contains(const T &) const;
            virtual Integer size() const
            {
                return m_size;
            }
            virtual Boolean empty() const
            {
                return Boolean(m_size == 0);
            }
            virtual ArrayList<T> to_array() const;
            virtual void clear();
            virtual Pointer begin() const;
            virtual Pointer end() const;
            virtual Pointer v_begin() const;
            virtual Pointer v_end() const;
            virtual String get_name() const override
            {
                return "Action::HashSet";
            }
            virtual String to_string() const override
            {
                return to_array().to_string();
            }
            virtual ~HashSet();
            const static Integer BEGIN_SPACE;
            const static Integer EVERY_INCREASE;
            const static Real INCREASE_CAPACITY;
        protected:
            LinkedList<T> * m_links;
            int m_size;
            int m_link_capacity;
            void auto_increase();
    };
}

#endif /* Action__HashSet */
