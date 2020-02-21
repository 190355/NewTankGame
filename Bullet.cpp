#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

#define FLOAT 0,02

//�R���X�g���N�^
Bullet::Bullet(GameObject * parent)
	:GameObject(parent, "Bullet"), hModel_(-1), move_(XMVectorSet(0, 0, 0, 0)), SPEED(0.5f)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 0.7f);
	AddCollider(collision);
}

//�X�V
void Bullet::Update()
{
	transform_.position_ += move_;

	move_.vecY -= FLOAT;
	if (transform_.position_.vecY < -10)
		KillMe();
}

//�`��
void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}

//����
void Bullet::Shot(XMVECTOR position, XMVECTOR direction)
{
	//���ˈʒu
	transform_.position_ = position;

	//�ړ��x�N�g��
	//XMVector3Normalize�Ő��K������ "* SPEED"�i�X�J���[�{�j�ő��x������
	move_ = XMVector3Normalize(direction) * SPEED;
}
