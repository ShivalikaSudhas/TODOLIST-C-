// #include <iostream>
// #include <vector>
// #include <string>
// #include <emscripten/emscripten.h>

// using namespace std;

// // browser input
// string ask(string msg) {
//     string js = "prompt('" + msg + "')";
//     return emscripten_run_script_string(js.c_str());
// }

// int main() {
//     vector<string> todos;

//     while (true) {
//         string choice = ask(
//             "Todo List Menu:\n"
//             "1. Add Task\n"
//             "2. View Tasks\n"
//             "3. Remove Task\n"
//             "4. Exit\n"
//             "Enter your choice:"
//         );

//         if (choice == "1") {
//             string task = ask("Enter task:");
//             todos.push_back(task);

//         } else if (choice == "2") {
//             cout << "\n----- YOUR TODO LIST -----\n";
//             for (int i = 0; i < todos.size(); i++) {
//                 cout << i+1 << ". " << todos[i] << endl;
//             }
//             cout << "--------------------------\n";

//         } else if (choice == "3") {
//             string pos = ask("Enter task number to remove:");
//             int index = stoi(pos) - 1;

//             if (index >= 0 && index < todos.size()) {
//                 todos.erase(todos.begin() + index);
//             } else {
//                 cout << "Invalid task number!\n";
//             }

//         } else if (choice == "4") {
//             cout << "Exiting Todo List. Bye!\n";
//             break;
//         }
//     }

//     return 0;
// }

// #include <vector>
// #include <string>
// #include <emscripten/bind.h>
// #include <emscripten.h>

// using namespace std;

// vector<string> todos;

// void addTask(string t) {
//     todos.push_back(t);
// }

// vector<string> getTasks() {
//     return todos;
// }

// void removeTask(int index) {
//     if (index >= 0 && index < todos.size()) {
//         todos.erase(todos.begin() + index);
//     }
// }

// EMSCRIPTEN_BINDINGS(todo_bindings) {
//     emscripten::function("addTask", &addTask);
//     emscripten::function("getTasks", &getTasks);
//     emscripten::function("removeTask", &removeTask);
//     emscripten::register_vector<string>("vector<string>");
// }

// #include <vector>
// #include <string>
// #include <emscripten/bind.h>

// using namespace std;

// // Global todo list (persists in WASM memory)
// vector<string> todos;

// // Add a new task
// void addTask(string task) {
//     if (!task.empty()) {
//         todos.push_back(task);
//     }
// }

// // Get all tasks
// vector<string> getTasks() {
//     return todos;
// }

// // Remove task by index
// void removeTask(int index) {
//     if (index >= 0 && index < todos.size()) {
//         todos.erase(todos.begin() + index);
//     }
// }

// // Optional: clear all tasks
// void clearTasks() {
//     todos.clear();
// }

// // Bind functions to JavaScript
// EMSCRIPTEN_BINDINGS(todo_bindings) {
//     emscripten::function("addTask", &addTask);
//     emscripten::function("getTasks", &getTasks);
//     emscripten::function("removeTask", &removeTask);
//     emscripten::function("clearTasks", &clearTasks);
//     emscripten::register_vector<string>("vector<string>");
// }

// #include <vector>
// #include <string>
// #include <emscripten/bind.h>

// using namespace std;

// // Todo structure
// struct Todo {
//     string text;
//     bool done;
// };

// // Global list (persists in WASM)
// vector<Todo> todos;

// // Add a task
// void addTask(string task) {
//     if (!task.empty()) {
//         todos.push_back({task, false});
//     }
// }

// // Toggle checklist (done / not done)
// void toggleTask(int index) {
//     if (index >= 0 && index < todos.size()) {
//         todos[index].done = !todos[index].done;
//     }
// }

// // Delete a task
// void deleteTask(int index) {
//     if (index >= 0 && index < todos.size()) {
//         todos.erase(todos.begin() + index);
//     }
// }

// // Get task count
// int getCount() {
//     return todos.size();
// }

// // Get task text
// string getText(int index) {
//     return todos[index].text;
// }

// // Get task status
// bool isDone(int index) {
//     return todos[index].done;
// }

// // Bindings
// EMSCRIPTEN_BINDINGS(todo_bindings) {
//     emscripten::function("addTask", &addTask);
//     emscripten::function("toggleTask", &toggleTask);
//     emscripten::function("deleteTask", &deleteTask);
//     emscripten::function("getCount", &getCount);
//     emscripten::function("getText", &getText);
//     emscripten::function("isDone", &isDone);
// }
#include <vector>
#include <string>
#include <emscripten/bind.h>

using namespace std;

struct Todo {
    string text;
    bool done;
};

vector<Todo> todos;

void addTask(string task) {
    if (!task.empty()) {
        todos.push_back({task, false});
    }
}

void toggleTask(int index) {
    if (index >= 0 && index < todos.size()) {
        todos[index].done = !todos[index].done;
    }
}

void deleteTask(int index) {
    if (index >= 0 && index < todos.size()) {
        todos.erase(todos.begin() + index);
    }
}

int getCount() {
    return todos.size();
}

string getText(int index) {
    return todos[index].text;
}

bool isDone(int index) {
    return todos[index].done;
}

EMSCRIPTEN_BINDINGS(todo_bindings) {
    emscripten::function("addTask", &addTask);
    emscripten::function("toggleTask", &toggleTask);
    emscripten::function("deleteTask", &deleteTask);
    emscripten::function("getCount", &getCount);
    emscripten::function("getText", &getText);
    emscripten::function("isDone", &isDone);
}
