#include "Ground.h"
#include "Engine/Model.h"

//コンストラクタ
Ground::Ground(GameObject * parent)
	:GameObject(parent, "Ground"), hModel_(-1)
{
}

//デストラクタ
Ground::~Ground()
{
}

//初期化
void Ground::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Ground.fbx");
	assert(hModel_ >= 0);
}

//更新
void Ground::Update()
{
}

//描画
void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Ground::Release()
{
}