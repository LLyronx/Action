#include "Action.h"
using namespace Action;

int main()
{
    //����ʹ�����ǵĿ⿪ʼ������

    //���������򵥵�Hello World��
    String hello="Hello World!";
    hello.println();

    //����ѧ��ʹ��������ʵ����
    Integer a=3,b=4;
    (a+b).println();
    (a-b).println();
    (a*b).println();
    (a/b).println();    //��������ʵ����
    (a DIV b).println();    //��仰�ܴﵽԭ��C++�������������������Ч����
    (a MOD b).println();    //���ǵ�%ȡ�������������MOD�����ˡ�

    //����ѧ��ʹ�����飡
    ArrayList<Integer> my_array;    //ֱ�Ӵ���һ����̬���飬����ʹ��vectorһ����
    my_array.push_back(100);  //����������׷��Ԫ��
    my_array.println(); //���
    my_array.insert(0,4);   //�ڵ�0��λ�ò�������4
    my_array.erase(1);  //�Ƴ���1��λ�õ�����100��
    my_array.println();

    //���ڴ���һ�����ϣ����������Ԫ���ǲ��ظ��ġ�
    HashSet<String> my_set;
    my_set.insert("Bye");
    my_set.insert("Hello");
    my_set.insert("Bye");
    my_set.println();   //����������ǣ���ЩԪ�ض�������ġ�

    //�ֵ���ʹ�ù�ϣ�ṹʵ�ֵģ�ʹ���ֵ������߲���Ч�ʡ�
    HashMap<String,Integer> my_map; //�����ֵ䣬����String��ֵ��Integer
    my_map.insert("China",1);
    my_map["America"]=2;    //������һ�ֲ��뷽ʽ
    my_map.insert("China",2);   //��������ظ��ļ�����ô��Ӧ��ֵ�ᱻ�滻
    my_map.println();

    //���к�ջ���������ƴ������㣬���ڳ���ʹ�����ǣ�
    Queue<Integer> my_que;
    my_que.push(3);
    my_que.push(2);
    my_que.front().println();
    my_que.pop();   //�Ƴ���ͷ��Ԫ��
    my_que.println();   //�ٿ�һ�Σ�����ֻ��һ��Ԫ����

    Stack<String> my_stk;
    my_stk.push("Hello");
    my_stk.push("Bye");
    my_stk.pop().println(); //������Ŷ

    //�ѿ�����Ϊ���ȶ��У����ʱ��Ϳռ临�Ӷȡ�
    //���ﲻ����ʾ��ʹ���߿����Լ����Կ���

    //��лʹ�ã�
    //Powered By Windows NT Version 6.0 Pre.
    return 0;
}
