#include <iostream>
#include <thread>

class thread_guard {
  std::thread &t;

public:
  explicit thread_guard(std::thread &t_) : t(t_) {}

  ~thread_guard() {
    if (t.joinable()) {
      t.join();
    }
  }

  thread_guard(thread_guard const &) = delete;
  thread_guard &operator=(thread_guard const &) = delete;
};

struct func {
  int &i;

  func(int &i_) : i(i_) {}

  void operator()() {
    for (unsigned j = 0; j < 100000; j++) {
      std::cout << i;
    }
  }
};

void f() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread t(my_func);
  thread_guard g(t);

  // do something
  std::cout << "do something work";
}

void hello() { std::cout << "hello concurrent :/"; }

class background_task {
public:
  void operator()() const {
    hello();
    hello();
  }
};


int main() {
  background_task f;
  std::thread t1{hello};
  std::thread t2(f);

  t1.join();
  t2.join();

  std::thread t3([] { hello(); });

  t3.join();

  return 0;
}
