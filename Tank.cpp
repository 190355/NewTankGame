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
	/*
	Ground* pGround = (Ground*)FindObject("Ground");    //�X�e�[�W�I�u�W�F�N�g��T��
	int hGroundModel = pGround->GetModelHandle();       //���f���ԍ����擾

	RayCastData data;
	data.start = transform_.position_;   //���C�̔��ˈʒu
	data.dir = XMVectorSet(0, -2, 0, 0); //���C�̕���
	Model::RayCast(hGroundModel, &data); //���C�𔭎�

	//���C������������
	if (data.hit)
	{
		//���̕��ʒu��������
		transform_.position_.vecY -= data.dist;
	}

	//���C������������
	if (!data.hit)
	{
		//���̕��ʒu��������
		transform_.position_.vecY += 0.1f;
	}

	//�J������TPS�̂悤�Ƀ}�E�X�𓮂�����Y���Œ�ŉ�
	Camera::SetPosition(XMVectorSet(transform_.position_.vecX, (transform_.position_.vecY + 3.0f), (transform_.position_.vecZ - 10.0f), 0.0f));
	Camera::SetTarget(XMVectorSet(transform_.position_.vecX, transform_.position_.vecY, transform_.position_.vecZ, 0.0f));
	*/

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
	XMVECTOR camVec = { 0,4,-7,0 };
	camVec = XMVector3TransformCoord(camVec, mat);
	Camera::SetPosition(transform_.position_ + camVec);
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