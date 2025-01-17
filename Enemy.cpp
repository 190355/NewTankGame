#include "Enemy.h"
#include "Engine/Model.h"

//コンストラクタ
Enemy::Enemy(GameObject * parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);

	Model::SetAnimFrame(hModel_, 1, 150, 1);
}

//更新
void Enemy::Update()
{
}

//描画
void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Enemy::Release()
{
}