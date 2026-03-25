CeladonCity_Apartments_2F_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{JPN}{PLAYER}は パソコンの\n"
	.string "{JPN}でんげんを いれた.\p"
	.string "{JPN}...\p"
	.string "{JPN}だれかが でんしメールを\n"
	.string "{JPN}かいている とちゅうだった.\p"
	.string "{JPN}...カントーちほうに\n"
	.string "{JPN}あそびに きてください.\p"
	.string "{JPN}ここの ようすが どのくらい\n"
	.string "{JPN}かわったか おどろくと おもいます.\p"
	.string "{JPN}ジョウトちほうには いない\n"
	.string "{JPN}ポケモンも たくさん みられます.\pプロデューサーへ\p...$"
CeladonMansion2F_Text_DevOfficeSign:
	.string "{JPN}ハート&ソウル かいはつしつ$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "{JPN}やあ みんな!パッチ15--\p"
	.string "{JPN}あっ ごめん...\p"
	.string "{JPN}やあ!ぼくは ゲームディレクター\n"
	.string "{JPN}だよ!\p"
	.string "{JPN}マップや タイルセット\n"
	.string "{JPN}スクリプトなどを つくったんだ.\p"
	.string "{JPN}でも ほかの かいはつしゃや\n"
	.string "{JPN}テストプレイヤーの みんなが\l"
	.string "{JPN}iなかったら できなかったよ.\pプレイしてくれて ありがとう!\nポケモン ハート&ソウルを\ltのしんでもらえたら うれしいな!$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "{JPN}いま pokeemerald expansion で\n"
	.string "{JPN}このゲームを さいこうちくしてる\lところなんだ!$"

CeladonMansion2F_Text_TixoRebel:
	.string "{JPN}THE EGGENING って しってる?\n"
	.string "{JPN}テストプレイちゅうの バグで\l"
	.string "{JPN}ポケモンが ランダムに タマゴに\l"
	.string "{JPN}へんかしちゃうやつ!\p"
	.string "{JPN}そのバグの しゅうせいを\nかいはつしたのは ぼくなんだ!$"

CeladonMansion2F_Text_Phant:
	.string "{JPN}ぼくは リメイクが だいすき!\p"
	.string "{JPN}ソード シールド アルティメット\n"
	.string "{JPN}プラス えいごばんを やったこと\l"
	.string "{JPN}ある? ぼくが ほんやくしたんだ!\p"
	.string "{JPN}つぎの リメイクでは\n"
	.string "{JPN}アローラを やってみようかな!$"

CeladonMansion2F_Text_Exclsior:
	.string "{JPN}かくポケモンの ユニークな\n"
	.string "{JPN}なみのりスプライトを\l"
	.string "{JPN}じっそうしたよ!\p"
	.string "{JPN}プロジェクトは オープンソースだ\nから きみも きのうを ついか\lできるよ!$"

CeladonMansion2F_Text_DaniRaibow:
	.string "{JPN}こんにちは!\p"
	.string "{JPN}わたしは もんだいを みつけるの\n"
	.string "{JPN}が とくいで ちいさなものなら\l"
	.string "{JPN}なおせるのよ.\p"
    .string "{JPN}ジョークを きく?\p"
	.string "{JPN}ワタルが カイリューに\n"
    .string "{JPN}りゅうのいきを おしえようと\l"
	.string "{JPN}したの.\p"
    .string "{JPN}でも カイリューは しんそくで\nはやく うごきすぎて\lつかまえられなかった!$"
