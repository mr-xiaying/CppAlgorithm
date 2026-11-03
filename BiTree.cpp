#include <iostream>
#include <algorithm>
using namespace std;

typedef char ElemType;  //定义二叉树结点值的类型为字符型
typedef struct BiTNode
{ElemType data;
    struct BiTNode *lchild,*rchild;
    
}BiTNode, *BiTree;

int LEAFCOUNT=0;
int NODECOUNT=0;

//按先序次序输入，以特殊字符表示空树
void CreateBiTree(BiTree &T){
    char ch;
    if(!(cin>>ch)){return;}
    if(ch=='#'){
        T =NULL;
        }else{
            T =new BiTNode;
            T ->data = ch;
            CreateBiTree(T ->lchild);
            CreateBiTree(T ->rchild);

        }


    
}

//先序遍历 
void PreOrderTraverse(BiTree T)
{
  if(T ==NULL){return;}
  cout<< T->data<<" ";
  PreOrderTraverse(T ->lchild);
  PreOrderTraverse(T ->rchild);

    
}

//中序遍历 
void InOrderTraverse(BiTree T)
{  if(T ==NULL){return;}
   InOrderTraverse(T ->lchild);
    cout<< T->data<<" ";
   InOrderTraverse(T ->rchild);

    
}

//后序遍历
void PostOrderTraverse(BiTree T)
{   if(T ==NULL){return;}
    PostOrderTraverse(T ->lchild);
    PostOrderTraverse(T ->rchild);
    cout<< T->data<<" ";
     


    
}

//求二叉树的深度
int BTDepth(BiTree T)
{
  if(T ==NULL){return 0;}
  int LeftDepth =BTDepth(T ->lchild);
  int RightDepth =BTDepth(T ->rchild);
  return max(LeftDepth,RightDepth)+1;

    
}

//求二叉树的叶子数, 使用全局变量
void Leaf(BiTree T)
{if(T ==NULL){return;}
 if(T->lchild == NULL&& T->rchild==NULL){
    LEAFCOUNT++;

 }
 Leaf(T->lchild);
 Leaf(T->rchild);

 

    
}
  
void NodeCount(BiTree T)//求二叉树的结点总数, 使用全局变量
{if(T ==NULL){return;}
 NODECOUNT++;
 NodeCount(T->lchild);
 NodeCount(T->rchild);

    
}

int main()
{
    BiTree T=NULL;
    int select;
    while(cin>>select)
    {
  
        switch(select)
        {
            case 0: 
                return 0;
            case 1:
                cin.clear();//清空输入
                CreateBiTree(T);
                break;
            case 2:
                if(T) {
                    PreOrderTraverse(T); 
                    cout<<endl;
                }
                break;
            case 3:
                if(T) {
                    InOrderTraverse(T);
                    cout<<endl;
                }
                break;
            case 4:
                if(T) {
                    PostOrderTraverse(T);
                    cout<<endl;
                }
                break;
            case 5:
cout<<BTDepth(T)<<endl;
                break;
            case 6:
                LEAFCOUNT=0;
                Leaf(T);
                cout<<LEAFCOUNT<<endl;
                break;
            case 7:
                NODECOUNT=0;
                NodeCount(T);
                cout<<NODECOUNT<<endl;
                break;
          }
    }
    return 0; 
}
