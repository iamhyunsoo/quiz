class BrowserHistory {
    std::vector<std::string> history_;
    int cur_page_ = 0;
    int last_page_ = 0;
public:
    BrowserHistory(string homepage) {
        history_.push_back(homepage);
    }
    
    void visit(string url) {
        if (history_.size() > cur_page_ + 1) {
            history_[cur_page_ + 1] = url;
        } else {
            history_.push_back(url);
        }
        last_page_ = cur_page_ + 1;
        cur_page_ = last_page_;
    }
    
    string back(int steps) {
        cur_page_ -= std::min(cur_page_, steps);
        return history_[cur_page_];
    }
    
    string forward(int steps) {
        cur_page_ += std::min((last_page_ - cur_page_), steps);
        return history_[cur_page_];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
