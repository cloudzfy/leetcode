class SnakeGame {
private:
    deque<pair<int, int> > snake;
    vector<pair<int, int> > food;
    int width, height;
    unordered_map<string, pair<int, int> > m;
    int foodCount;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        snake.push_back(make_pair(0, 0));
        this->food = food;
        this->width = width;
        this->height = height;
        m["U"] = make_pair(-1, 0);
        m["L"] = make_pair(0, -1);
        m["R"] = make_pair(0, 1);
        m["D"] = make_pair(1, 0);
        foodCount = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int x = snake[0].first + m[direction].first;
        int y = snake[0].second + m[direction].second;
        if (checkBoundary(x, y)) {
            for (int i = 0; i < snake.size() - 1; i++) {
                if (x == snake[i].first && y == snake[i].second) return -1;
            }
            if (foodCount < food.size() && x == food[foodCount].first && y == food[foodCount].second) {
                foodCount++;
            } else {
                snake.pop_back();
                
            }
            snake.push_front(make_pair(x, y));
            return foodCount;
        }
        return -1;
    }
    
    bool checkBoundary(int x, int y) {
        return x < height && x >= 0 && y < width && y >= 0;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
