#include "Cannon.h"
#include "Bullet.h"
#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"

//�R���X�g���N�^
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1), hSound_(-1), SWING_SPEED(3.0f)
{
}

//�f�X�g���N�^
Cannon::~Cannon()
{
}

//������
void Cannon::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);

	//�T�E���h�f�[�^�̃��[�h
	hSound_ = Audio::Load("CannonShot.wav");
	assert(hSound_ >= 0);
}

//�X�V
void Cannon::Update()
{
	//A�L�[��������Ă�����
	if (Input::IsKey(DIK_LEFT))
	{

		transform_.rotate_.vecY -= SWING_SPEED;
	}

	//D�L�[��������Ă�����
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.vecY += SWING_SPEED;
	}

	//�X�y�[�X�L�[����������
	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet* pBullet = Instantiate<Bullet>(FindObject("PlayScene"));
		XMVECTOR shotPos = Model::GetBonePosition(hModel_, "ShotPoint");
		XMVECTOR cannonRoot = Model::GetBonePosition(hModel_, "CannonRoot");

		pBullet->Shot(shotPos, shotPos - cannonRoot);

		Audio::Play(hSound_);
	}
}

//�`��
void Cannon::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Cannon::Release()
{
}