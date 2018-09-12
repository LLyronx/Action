#include "Action.h"
#include <stdlib.h>
#include <time.h>
using namespace Action;

int main()
{
    //����ʹ�����ǵĿ⿪ʼ������
    srand(time(NULL));  //��һЩ�������׼��

    //���������򵥵�Hello World��
    String hello = "Hello World!";
    hello.println();
    (hello + " We are coding now!").println();   //��������������������ַ�������ƴ�ӡ�

    //����ѧ��ʹ��������ʵ����
    Integer a = 3, b = 4;
    (a + b).println();
    (a - b).println();
    (a * b).println();
    (a / b).println();  //��������ʵ����
    (a DIV b).println();    //��仰�ܴﵽԭ��C++�������������������Ч����
    (a MOD b).println();    //���ǵ�%ȡ�������������MOD�����ˡ�

    //����ѧ��ʹ�����飡
    ArrayList<Integer> my_array;    //ֱ�Ӵ���һ����̬���飬����ʹ��vectorһ����
    my_array.push_back(100);  //����������׷��Ԫ��
    my_array.println(); //���
    my_array.insert(0, 4);  //�ڵ�0��λ�ò�������4
    my_array.erase(1);  //�Ƴ���1��λ�õ�����100��
    my_array.println();

    //��������鶼�����Խṹ������������̶ȵ����ÿռ䡣
    LinkedList<Integer> my_links;
    my_links.push_back(1);
    my_links.push_back(3);
    my_links.println();
    for(LinkedList<Integer>::Pointer it = my_links.begin(); it != my_links.end(); ++it)
    {
        (*it).println();    //�������õ�������Ԫ�ر�������ɣ�
    }
    String("The following operation is deprecated!").println();
    my_links[1].println();  //�����Ȳ����ѵ�ʱ��Ҫ�±���ʣ���������Ҫ����ʹ��ArrayList��

    //���ڴ���һ�����ϣ����������Ԫ���ǲ��ظ��ġ�
    HashSet<String> my_set;
    my_set.insert("Bye");
    my_set.insert("Hello");
    my_set.insert("Bye");
    my_set.println();   //����������ǣ���ЩԪ�ض�������ġ�

    //����ļ���TreeSet���԰���������Ŷ����������һ�ԣ�
    TreeSet<Integer> another_set;
    for(int i = 0; i < 100; ++i)
    {
        another_set.insert(rand() % 50);
    }
    another_set.println();  //���Կ���TreeSet����ȥ�����ظ�Ԫ�أ������ź�����

    //�ֵ���ʹ�ù�ϣ�ṹʵ�ֵģ�ʹ���ֵ������߲���Ч�ʡ�
    HashMap<String, Integer> my_map; //�����ֵ䣬����String��ֵ��Integer
    my_map.insert("China", 1);
    my_map["America"] = 2;  //������һ�ֲ��뷽ʽ
    my_map.insert("China", 2);  //��������ظ��ļ�����ô��Ӧ��ֵ�ᱻ�滻
    my_map.println();   //���ڴ�ӡһ�½��
    my_map.clear();     //���Ҫ��������ֵ䣬����ʹ��clear������
    for(int i = 0; i < 100; ++i)    //��������������������Ƿ�����
    {
        String temp;
        for(int j = 0; j < 5; ++j)
        {
            temp += (rand() % 26 + 'a');
        }
        my_map.insert(temp, rand());
    }
    my_map.println();   //���Է��֣�����������ġ�

    //��������ֵ��ڲ�ʹ�ö�����ʵ�֣�������������������ٰѸղŵ�ʵ����һ�顣
    TreeMap<String, Integer> another_map;
    for(int i = 0; i < 100; ++i)    //�����ֵ�ķ���������ȫ��ͬ��
    {
        String temp;
        for(int j = 0; j < 5; ++j)
        {
            temp += (rand() % 26 + 'a');
        }
        another_map.insert(temp, rand());
    }
    another_map.println();   //���Է��֣�����������ġ�

    //���к�ջ���������ƴ������㣬���ڳ���ʹ�����ǣ�
    Queue<Integer> my_que;
    my_que.push(3);
    my_que.push(2);
    my_que.front().println();
    my_que.pop();   //�Ƴ���ͷ��Ԫ��
    my_que.println();   //�ٿ�һ�Σ�����ֻ��һ��Ԫ����

    Deque<Integer> my_dqe;  //˫�˶��п��������˲������ȡ��Ԫ��
    my_dqe.push_back(5);
    my_dqe.push_back(6);
    my_dqe.push_front(7);
    my_dqe.push_front(8);
    my_dqe.println();
    my_dqe[2].println();    //�±����ĳ��Ԫ��
    my_dqe.pop_back().println();
    my_dqe.pop_front().println();
    my_dqe.println();

    Stack<String> my_stk;
    my_stk.push("Hello");
    my_stk.push("Bye");
    my_stk.pop().println(); //������Ŷ

    //ʹ�öѣ�Heap������ʵ�����ȶ��еĹ��ܣ����ǿ�����Heap�๹��һ����С�ѡ�
    ArrayList<Integer> temp_array;
    for(int i = 0; i < 10; ++i)
    {
        temp_array.push_back(rand());
    }
    Heap<Integer> my_heap(temp_array);
    my_heap.println();  //���ݴ�ӡ�����ݣ����ܷ񻭳�һ����С���أ����Կ��ɣ�

    //��лʹ�ã�
    //Powered By Windows NT Version 6.0 Pre.
    return 0;
}
