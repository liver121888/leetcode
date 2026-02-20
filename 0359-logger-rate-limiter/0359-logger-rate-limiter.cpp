// All messages will come in chronological order. Several messages may arrive at the same timestamp.
// we can have a hash map, message, last time
// if the message is not in the map, put it in with timestamp
// if it's in, check if the timestamp has passed 10 sec,
// if yes, print and update
// if not, don't update

class Logger {
public:

    unordered_map<string, int> lastTime;


    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if (lastTime.find(message) == lastTime.end() || timestamp - lastTime.at(message) >= 10) {
            lastTime[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */