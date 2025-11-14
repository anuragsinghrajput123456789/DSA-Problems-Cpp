Node<int>* reverse(Node<int>* head){

    Node<int>* curr=head;

    Node<int>* prev=NULL;

    Node<int>* next=NULL;

    while(curr!=NULL){

        next=curr->next;

        curr->next=prev;

        prev=curr;

        curr=next;

    } 

    return prev;  

}

void insertAtTail(Node<int>* &head, Node<int>* &tail,int digit){

    Node<int>* ans=new Node<int>(digit);

    if(head == NULL){

        head=ans;

        tail=ans;

        return;

    }

    else{

        tail->next=ans;

        tail=ans;

    }

}

Node<int>* add(Node<int>* first, Node<int>* second){

    int carry=0;

    Node<int>* ansHead=NULL;

    Node<int>* ansTail=NULL;

    while(first !=NULL ||second!=NULL || carry!=0){

        int val1=0;

        if(first!=NULL){

            val1=first->data;

        }

        int val2=0;

        if(second!=NULL){

            val2=second->data;

        }

        int sum=val1+val2+carry;

        int digit=sum%10;

        insertAtTail(ansHead,ansTail,digit);

        carry=sum/10;

        if(first!=NULL){

            first=first->next;

        }

        if(second!=NULL){

            second=second->next;

        }

    }

    return ansHead;

}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {

    first=reverse(first);

    second=reverse(second);

    Node<int>* ans=add(first,second);

    ans=reverse(ans);

    return ans;

}