#include <iostream>
#include "Exception.h"

#ifndef Action__Integer_OutOfBound
#define Action__Integer_OutOfBound
namespace Action
{
    class Integer;
	class Integer_OutOfBound: public Exception
	{
	public:
        Integer_OutOfBound(int fal_value):m_false_value(fal_value){}
        Integer getValue() const;
		String getName() const override;
		String toString() const override;
    private:
        int m_false_value;
	};
}
#endif  /* Action__Integer_OutOfBound */
