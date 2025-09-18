class TaskManager {
public:
    typedef pair<int,int>p;
    priority_queue<p>max_heap;  //priority task_id
    unordered_map<int,int>task_pri;
    unordered_map<int,int>task_user;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto it: tasks){
            add(it[0],it[1],it[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        max_heap.push({priority,taskId});
        task_pri[taskId]=priority;
        task_user[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        max_heap.push({newPriority,taskId});
        task_pri[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        task_pri[taskId]=-1;
    }
    
    int execTop() {
        while(!max_heap.empty()){
            auto[priority,taskid]=max_heap.top();
            max_heap.pop();

            if(priority==task_pri[taskid]){   // priority if -1 igone because it is removed
                task_pri[taskid]=-1;  // make it used
                return task_user[taskid];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */