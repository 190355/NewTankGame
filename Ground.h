#pragma once
#include "Engine/GameObject.h"

//Tankを管理するクラス
class Ground : public GameObject
{
	int hModel_;    //モデル番号
public:
	//コンストラクタ
	Ground(GameObject* parent);

	//デストラクタ
	~Ground();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//地面のモデル番号を取得
	int GetModelHandle() { return hModel_; }
};