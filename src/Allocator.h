#include <iostream>
#include <memory.h>
#include <stdlib.h>
#include "Integer.h"
#include "Object.h"
#include "Alloc_OutOfMemory.h"

/*
    月亮在白莲花般的云朵里穿行
    晚风吹来一阵阵欢乐的歌声
*/

#ifndef Action__Allocator
#define Action__Allocator
namespace Action
{
    template <class T>
    class Allocator : public Object
    {
        private:
            void auto_increase();
        public:
            const static Integer EVERY_INCREASE;
            const static Integer BEGIN_SPACE;

            Allocator();
            virtual void set_capacity(Integer);
            virtual inline Integer get_capacity() const
            {
                return m_capacity;
            }
            virtual void construct(Integer, const T &);
            virtual void destruct(Integer);
            virtual T * get_space();
            virtual String get_name() const;
            virtual ~Allocator();

#if __cplusplus < 201103L
        private:
            Allocator & operator = (const Allocator &);
            Allocator(const Allocator &);
#else
            void operator = (const Allocator &) = delete;
            Allocator(const Allocator &) = delete;
#endif

        private:
            T * m_space;
            int m_capacity;
            int m_next_capacity;
    };
}
#endif /* Action__Allocator */
