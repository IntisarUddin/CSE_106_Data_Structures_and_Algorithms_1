#include"StackUsingQueue.h"
#include<iostream>
using namespace std;
void Sort(Queue &q){
    Stack st;

    //stack.push(queue.dequeue());
    while(!q.isEmpty()){

        int top = q.dequeue();
        while(!st.isEmpty() && top > st.top()){
            int st_top = st.pop();
            q.enqueue(st_top);
        }
        st.push(top);

    }

    while(!st.isEmpty()){
        cout<<st.pop()<<" ";
    }
    cout<<endl;
    return;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        Queue q;
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            q.enqueue(x);
        }
        cout<<endl;
        Sort(q);
        cout<<endl;
    }
    return 0;
}