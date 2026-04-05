

// Every timestamp will be passed in non-decreasing order (chronological order).
// we can save a time that a message is print
// we can use an unordered_map to achieve this

class Logger {
public:

    unordered_map<string, int> eventLog;
    const int coolDown = 10;

    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {

        if (eventLog.find(message) != eventLog.end() 
            && timestamp < eventLog[message] + coolDown) {
            return false;
        }

        eventLog[message] = timestamp;
        return true;
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */