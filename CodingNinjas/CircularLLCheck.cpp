bool isCircular(Node* head){
    // Write your code here.

    if(!head)return true;

    if(!head->next)return false;

    Node *slow=head;
    Node *fast=head;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }

    if(slow==head && slow==fast )return true;

    return false;
}