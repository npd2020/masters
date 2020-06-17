#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct cell {
    int y;  // numbers
    int x;  // letters
    int d;  // distance
};

struct node {
    cell val;
    node* next;
    node(cell v, node* n = NULL) {
        val = v;
        next = n;
    }
};

struct Queue {
    node* head;
    Queue(node* h = NULL) {
        head = h;
    }
    void push(cell v) { // add element
        head = new node(v, head);
    }
    cell pop() {    // remove element
        if((head -> next) != NULL) {
            node *i = head;
            node *p = i;
            while(i -> next != NULL) {
                p = i;
                i = i -> next;
            }
            cell v = i -> val;
            p -> next = NULL;
            delete i;
            return v;
        } else {
            node *n = head;
            cell v = head -> val;
            head = head -> next;
            delete n;
            return v;
        }
    }
    void clear() {
        head = NULL;
    }
};

int main() {
    string str;
    Queue q;
    cell current, goal, next;
    bool visited[8][8];
    while(getline(cin, str)) {


        current.y = (int)(str[1] - '1');
        current.x = (int)(str[0] - 'a');
        goal.y = (int)(str[4] - '1');
        goal.x = (int)(str[3] - 'a');
        if(str == "")
            return 0;
        if(0 > current.y || current.y > 7 || 0 > current.x || current.x > 7 || 0 > goal.y || goal.y > 7 || 0 > goal.x || goal.x > 7){
            cout << "Wrong input. Input format is: \na1 h8\n";
            continue;
        }
        current.d = 0;

        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                visited[i][j] = false;
        visited[current.y][current.x] = true;


        q.push(current);

        // BFS
        while( !(current.y == goal.y && current.x == goal.x) ) {
            current = q.pop();
            next.d = current.d + 1;
            for(int i = -2; i <= 2; i++)
                if(i != 0)
                    for(int j = -(3 - abs(i)); j <= 3 - abs(i); j += 2 * (3 - abs(i))) {
                        next.y = current.y + i;
                        next.x = current.x + j;
                        if(0 <= next.y && next.y <= 7 && 0 <= next.x && next.x <= 7 && !visited[next.y][next.x]) {
                            q.push(next);
                            visited[next.y][next.x] = true;
                        }
                    }
        }

        cout << "To get from " << str[0] << str[1] << " to " << str[3] << str[4] << " takes " << current.d << " knight moves." << endl;

        q.clear();
    }
    return 0;
}
