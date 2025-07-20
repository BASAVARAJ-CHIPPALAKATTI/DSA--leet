class BrowserHistory {
public:
    struct node{
        node* prev=nullptr;
        node* next=nullptr;
        const string url;
        node(const string &url): url(url){}

    };
    node* curr;
    BrowserHistory(string homepage) {
        curr=new node(homepage);
    }
    
    void visit(string url) {
        curr->next=new node(url);
        curr->next->prev=curr;

        curr=curr->next;
    }
    
    string back(int steps) {

        while(curr->prev && steps-- >0){
            curr=curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next && steps-- >0){
            curr=curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */