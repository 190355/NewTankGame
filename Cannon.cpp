#include "Cannon.h"
#include "Bullet.h"
#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1), SWING_SPEED(3.0f)
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
		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->Shot(transform_.position_,XMVectorSet(0.3f,0,0,0));
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