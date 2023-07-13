#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_log.h>

#include "../include/Module/IncludeModule.h"

//-------------------------------Module实现
Module::Module(std::string name) : name(name) {}
Module::~Module() {}

//-------------------------------InputModule实现
InputModule *InputModule::ins = nullptr;

InputModule *InputModule::getIns() {
    if (InputModule::ins == nullptr) {
        InputModule::ins = new InputModule();
    }
    return InputModule::ins;
}

InputModule::InputModule() : Module("InputModule") {}

void InputModule::onLoad() {}
void InputModule::onUpdate(float dt) {
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    for (auto item : this->data) {
        if (item->caller->callerValid) {
            if (keyboardState[item->key]) {
                if (item->keyDownCall) item->keyDownCall();
            } else {
                if (item->keyUpCall) item->keyUpCall();
            }
        }
    }
}

void InputModule::onStart() {}

void InputModule::onClean() {
    auto temp = this->data.begin();
    while (temp != this->data.end()) {
        if (!(*temp)->caller->callerValid) {
            temp = this->data.erase(temp);
        } else {
            temp++;
        }
    }
}

void InputModule::registerHandle(KeyCode code,
                                 const std::function<void()> keyUpCall,
                                 const std::function<void()> keyDownCall,
                                 ICaller *caller) {
    auto temp = new HandleData();
    temp->key = code;
    temp->keyDownCall = keyDownCall;
    temp->keyUpCall = keyUpCall;
    temp->caller = caller;
    this->data.push_back(temp);
}

//-------------------------------ResourceModule实现
ResourceModule *ResourceModule::ins = nullptr;
ResourceModule *ResourceModule::getIns() {
    if (ResourceModule::ins == nullptr) {
        ResourceModule::ins = new ResourceModule();
    }
    return ResourceModule::ins;
}

ResourceModule::ResourceModule() : Module("ResourceModule") {}
void ResourceModule::onLoad() {}
void ResourceModule::onStart() {
    // this->loadRes("/assets/MyGame/player/run.png", AssetsType::TEXTURE);
    // this->loadRes("/assets/MyGame/player/death.png", AssetsType::TEXTURE);
    // this->loadRes("/assets/MyGame/player/idle.png", AssetsType::TEXTURE);
    // this->loadRes("/assets/MyGame/player/jump.png", AssetsType::TEXTURE);
    // // this->loadRes("/assets/MyGame/player/run.png", AssetsType::TEXTURE);
    // this->loadRes("/assets/MyGame/player/atk.png", AssetsType::TEXTURE);
}
void ResourceModule::onUpdate(float dt) {}
void ResourceModule::onClean() {}

void ResourceModule::loadRes(const std::string path, AssetsType type) {
    SDL_Texture *tex = IMG_LoadTexture(GameApp::getIns()->render, path.c_str());

    if (!tex) {
        SDL_Log("图片加载失败： %s", IMG_GetError());
        return;
    }

    switch (type) {
        case AssetsType::TEXTURE:
            this->tex_res[path] = tex;
            break;
        case FONT:
            break;
        case AUDIO:
            break;
    }
}

SDL_Texture *ResourceModule::getRes(std::string path, AssetsType type) {
    // switch (type) {
    //     case AssetsType::TEXTURE:
    return this->tex_res[path];
    //         break;
    //     case FONT:
    //         break;
    //     case AUDIO:
    //         break;
    // };
}

//-------------------------------StageModule实现
StageModule *StageModule::ins = nullptr;

StageModule *StageModule::getIns() {
    if (StageModule::ins == nullptr) {
        StageModule::ins = new StageModule();
    }
    return StageModule::ins;
}

StageModule::StageModule() : Module("GameCamera"), x(0.0), y(0.0){};

void StageModule::onLoad() {}
void StageModule::onStart() {}
void StageModule::onUpdate(float dt) {}
void StageModule::onClean() {}

Vec2 StageModule::worldToScreen(Vec2 &wps) {
    float w = GameApp::getIns()->width / 2.0;
    float h = GameApp::getIns()->heigh / 2.0;

    Vec2 temp;
    temp.x = wps.x + w + this->x;
    temp.y = wps.y + h + this->y;
    return temp;
}

void StageModule::screenToWorld(Vec2 &pos) {}

StageModule::~StageModule() {}

//-------------------------------ObjectModule实现
ObjectModule *ObjectModule::ins = nullptr;

ObjectModule::ObjectModule() : Module("ObjectModule") {}

void ObjectModule::onLoad() {}

void ObjectModule::onStart() {}

void ObjectModule::onUpdate(float dt) {
    for (auto item : this->activeObj) {
        if (!item->dirtyStart) item->start();
    }

    for (auto item : this->activeObj) {
        item->update(dt);
    }
}

void ObjectModule::render() {
    for (auto item : this->activeObj) {
        item->render();
    }
}

void ObjectModule::onClean() { this->destroyDeadObj(); }

void ObjectModule::addObj(GameRenderObj *obj) {
    this->activeObj.push_back(obj);
}
void ObjectModule::removeObj(GameRenderObj *obj) {
    auto resualt =
        std::find(this->activeObj.begin(), this->activeObj.end(), obj);

    if (resualt != this->activeObj.end()) {
        auto temp = *resualt;
        this->activeObj.erase(resualt);
        temp->valid = false;
        this->deadObj.push_back(temp);
    }
}

void ObjectModule::destroyDeadObj() {
    for (auto item : this->deadObj) {
        delete item;
    }
    this->deadObj.clear();
}

ObjectModule *ObjectModule::getIns() {
    if (ObjectModule::ins == nullptr) {
        ObjectModule::ins = new ObjectModule();
    }
    return ObjectModule::ins;
}

ObjectModule::~ObjectModule() {
    for (auto item : this->activeObj) {
        delete item;
    }
    this->activeObj.clear();

    for (auto item : this->deadObj) {
        delete item;
    }
    this->deadObj.clear();
}
