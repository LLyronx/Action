#include <iostream>
#include <memory.h>
#include <stdlib.h>
#include "Integer.h"
#include "Object.h"
#include "Alloc_OutOfMemory.h"

/*
	�����ڰ���������ƶ��ﴩ��,
	��紵��һ�����ֵĸ���
*/

#ifndef Action__Allocator
#define Action__Allocator
namespace Action
{
	//�ڴ�����������������ڴ�͵��ù��죬��������
	template <class T>
	class Allocator : public Object
	{
	private:
		void Auto_Increase();
	public:
        const static Integer EVERY_INCREASE;	//ÿ�����ݵı���
        const static Integer BEGIN_SPACE;	//��ʼ�ռ��С

		//���캯��
		Allocator();

		//�����´���Ҫ�Ŀռ䣨�´�����Ŀռ��ǲ����������������������)
		void SetCapacity(const Integer &);

		//����´���Ҫ����Ŀռ�
		inline Integer GetCapacity() const {return m_iCapacity;}
		
		//���Ե�һ������Ϊ�����±�Ŀռ��ϵ��ÿ������캯���������ڶ�������
		void Construct(const Integer &,const T &);

		//���Բ���Ϊ�����±�Ŀռ��ϵ�����������
		void Destruct(const Integer &);

		//�������ָ��
		T * GetSpace();

		//��ù�����������Ϣ
		String getName() const;

		//����������ֱ���ͷ�����ռ�
		~Allocator();
	private:
		T * m_tSpace;
		int m_iCapacity;
		int m_iNextCapacity;
	};
}
#endif /* Action__Allocator */
