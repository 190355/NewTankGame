#pragma once
#include "Engine/GameObject.h"

//戦車(下)を管理するクラス
class Tank : public GameObject
{
	int hModel_;    //モデル番号
	int hSound_;    //サウンド番号

public:
	//コンストラクタ
	Tank(GameObject* parent);

	//デストラクタ
	~Tank();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void FitHeightToGround();
};