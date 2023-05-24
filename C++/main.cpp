/*
 * Design Pattern - State 狀態模式
 * 
 * 在這個範例中，我們有一個狀態抽象類別 State，並有兩個具體的狀態類別 ConcreteStateA 和 ConcreteStateB。
 * Context 是上下文類別，其中維護了一個 State 的實例，表示上下文的當前狀態。
 * 在每個具體狀態類別中，我們實現了 Handle 方法來處理不同的狀態行為並進行狀態轉換。
 * 
 * 在客戶端程式碼中，我們創建了一個 Context 物件並將初始狀態設定為 ConcreteStateA。
 * 然後，我們依序執行 Request 方法，觀察狀態的變化。
 * 在每次呼叫 Request 時，該狀態的 Handle 方法會被調用，並執行對應的狀態行為和狀態轉換。
 * 
 */

#include <iostream>

class Context;

/*
 * 狀態抽象類別.
*/
class State {
public:
    virtual void Handle(Context* context) = 0;
};

/*
 * 具體狀態類別 A.
*/
class ConcreteStateA : public State {
public:
    void Handle(Context* context) override;
};

/*
 * 具體狀態類別 B.
*/
class ConcreteStateB : public State {
public:
    void Handle(Context* context) override;
};

/*
 * 上下文類別.
*/
class Context {
private:
    State* currentState;

public:
    Context() : currentState(nullptr) {}
    ~Context() {
        if (currentState)
            delete currentState;
    }

    void SetState(State* state) {
        if (currentState)
            delete currentState;
        currentState = state;
    }

    void Request() {
        if (currentState)
            currentState->Handle(this);
        else
            std::cout << "No state set" << std::endl;
    }
};

/*
 * 具體狀態類別 A 的行為實現.
*/
void ConcreteStateA::Handle(Context* context) {
    std::cout << "Executing behavior for concrete state A" << std::endl;
    // 狀態轉換.
    context->SetState(new ConcreteStateB());
}

/*
 * 具體狀態類別 B 的行為實現.
*/
void ConcreteStateB::Handle(Context* context) {
    std::cout << "Executing behavior for concrete state B" << std::endl;
    // 狀態轉換.
    context->SetState(new ConcreteStateA());
}

/*
 * 客戶端程式碼.
*/
int main() {
    Context context;

    // 初始狀態設定為 A.
    context.SetState(new ConcreteStateA());

    // 依序執行 Request，觀察狀態的變化.
    context.Request();
    context.Request();
    context.Request();
    context.Request();

    return 0;
}
