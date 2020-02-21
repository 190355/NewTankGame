#include "Cannon.h"
#include "Bullet.h"
#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"

//コンストラクタ
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1), hSound_(-1), SWING_SPEED(3.0f)
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

	//サウンドデータのロード
	hSound_ = Audio::Load("CannonShot.wav");
	assert(hSound_ >= 0);
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
		Bullet* pBullet = Instantiate<Bullet>(FindObject("PlayScene"));
		XMVECTOR shotPos = Model::GetBonePosition(hModel_, "ShotPoint");
		XMVECTOR cannonRoot = Model::GetBonePosition(hModel_, "CannonRoot");

		pBullet->Shot(shotPos, shotPos - cannonRoot);

		Audio::Play(hSound_);
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