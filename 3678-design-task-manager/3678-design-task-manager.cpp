class TaskManager {
public:

    priority_queue<pair<int,int>> q;
    unordered_map<int, pair<int,int>> task2info;

    TaskManager(vector<vector<int>>& tasks) {
        
        // taskId is unique
        // userId set to different bin
        // priority
        
        // priority, taskid


        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {

        task2info[taskId] = {userId, priority};
        q.push(make_pair(priority, taskId));
        
    }
    
    void edit(int taskId, int newPriority) {

        task2info[taskId].second = newPriority;
        q.push(make_pair(newPriority, taskId));
        
    }
    
    void rmv(int taskId) {

        task2info.erase(taskId);
        
    }
    
    int execTop() {
        
        while (!q.empty()) {
            const auto task = q.top();
            q.pop();
            auto p = task.first;
            auto t = task.second;
            if (task2info.find(t) != task2info.end() && task2info[t].second == p) {
                // execute
                int user = task2info[t].first;
                task2info.erase(t);
                return user;
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