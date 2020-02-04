#include "Tank.h"
#include "Ground.h"
#include "Bullet.h"
#include "Cannon.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

//コンストラクタ
Tank::Tank(GameObject * parent)
	:GameObject(parent, "Tank"), hModel_(-1)
{
}

//デストラクタ
Tank::~Tank()
{
}

//初期化
void Tank::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);

	//子供として砲台を追加
	Instantiate<Cannon>(this);
}

//更新
void Tank::Update()
{
	/*
	Ground* pGround = (Ground*)FindObject("Ground");    //ステージオブジェクトを探す
	int hGroundModel = pGround->GetModelHandle();       //モデル番号を取得

	RayCastData data;
	data.start = transform_.position_;   //レイの発射位置
	data.dir = XMVectorSet(0, -2, 0, 0); //レイの方向
	Model::RayCast(hGroundModel, &data); //レイを発射

	//レイが当たったら
	if (data.hit)
	{
		//その分位置を下げる
		transform_.position_.vecY -= data.dist;
	}

	//レイが当たったら
	if (!data.hit)
	{
		//その分位置を下げる
		transform_.position_.vecY += 0.1f;
	}

	//カメラをTPSのようにマウスを動かすとY軸固定で回す
	Camera::SetPosition(XMVectorSet(transform_.position_.vecX, (transform_.position_.vecY + 3.0f), (transform_.position_.vecZ - 10.0f), 0.0f));
	Camera::SetTarget(XMVectorSet(transform_.position_.vecX, transform_.position_.vecY, transform_.position_.vecZ, 0.0f));
	*/

	XMVECTOR move = { 0.0f,0.0f,0.1f,0.0f };

	XMMATRIX mat;
	mat = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));
	move = XMVector3TransformCoord(move, mat);

	//Wキーが押されていたら
	if (Input::IsKey(DIK_W))
	{
		transform_.position_ += move;
	}

	//Sキーが押されていたら
	if (Input::IsKey(DIK_S))
	{
		transform_.position_ -= move;
	}

	//Aキーが押されていたら
	if (Input::IsKey(DIK_A))
	{

		transform_.rotate_.vecY -= 1.0f;
	}

	//Dキーが押されていたら
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.vecY += 1.0f;
	}

	//カメラの見る位置
	Camera::SetTarget(transform_.position_);

	//カメラの位置
	XMVECTOR camVec = { 0,4,-7,0 };
	camVec = XMVector3TransformCoord(camVec, mat);
	Camera::SetPosition(transform_.position_ + camVec);
}

//描画
void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Tank::Release()
{
}