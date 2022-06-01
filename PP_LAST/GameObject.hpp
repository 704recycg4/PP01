#pragma once
class GameObject
{
public:
    GameObject() {}
    ~GameObject() {}
    virtual void Input() {}
    virtual void Update() {}
    virtual void Render() {}
};