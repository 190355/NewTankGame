#include "Tank.h"
#include "Ground.h"
#include "Bullet.h"
#include "Cannon.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
Tank::Tank(GameObject * parent)
	:GameObject(parent, "Tank"), hModel_(-1)
{
}

//�f�X�g���N�^
Tank::~Tank()
{
}

//������
void Tank::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);

	//�q���Ƃ��ĖC���ǉ�
	Instantiate<Cannon>(this);
}

//�X�V
void Tank::Update()
{
	XMVECTOR move = { 0.0f,0.0f,0.1f,0.0f };

	XMMATRIX mat;
	mat = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));
	move = XMVector3TransformCoord(move, mat);

	//W�L�[��������Ă�����
	if (Input::IsKey(DIK_W))
	{
		transform_.position_ += move;
	}

	//S�L�[��������Ă�����
	if (Input::IsKey(DIK_S))
	{
		transform_.position_ -= move;
	}

	//A�L�[��������Ă�����
	if (Input::IsKey(DIK_A))
	{

		transform_.rotate_.vecY -= 1.0f;
	}

	//D�L�[��������Ă�����
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.vecY += 1.0f;
	}

	//�J�����̌���ʒu
	Camera::SetTarget(transform_.position_);

	//�J�����̈ʒu
	XMVECTOR camVec = { 0,10,-25,0 };
	camVec = XMVector3TransformCoord(camVec, mat);
	Camera::SetPosition(transform_.position_ + camVec);

	FitHeightToGround();
}

//�`��
void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Tank::Release()
{
}

void Tank::FitHeightToGround()
{
	Ground* pGround = (Ground*)FindObject("Ground");    //�X�e�[�W�I�u�W�F�N�g��T��
	int hGroundModel = pGround->GetModelHandle();       //���f���ԍ����擾

	RayCastData data;
	data.start = transform_.position_;   //���C�̔��ˈʒu
	data.start.vecY = 0;

	data.dir = XMVectorSet(0, -1, 0, 0); //���C�̕���
	Model::RayCast(hGroundModel, &data); //���C�𔭎�

	//���C������������
	if (data.hit)
	{
		//���̕��ʒu��������
		transform_.position_.vecY = -data.dist;
	}
};