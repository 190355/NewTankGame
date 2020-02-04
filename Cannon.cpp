#include "Cannon.h"
#include "Bullet.h"
#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//コンストラクタ
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1), SWING_SPEED(3.0f)
{
}

//デストラクタ
Cannon::~Cannon()
{
}

//初期化
void Cannon::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);
}

//更新
void Cannon::Update()
{
	//Aキーが押されていたら
	if (Input::IsKey(DIK_LEFT))
	{

		transform_.rotate_.vecY -= SWING_SPEED;
	}

	//Dキーが押されていたら
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.vecY += SWING_SPEED;
	}

	//スペースキーを押したら
	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->Shot(transform_.position_,XMVectorSet(0.3f,0,0,0));
	}
}

//描画
void Cannon::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Cannon::Release()
{
}