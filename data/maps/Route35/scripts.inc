Route35_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "{JPN}ラジオから ポケモンの\n"
	.string "{JPN}じょうほうを きいてるんだ.\nぼくは つよいと おもうよ$"

Route35_Text_CamperIvanBeaten:
	.string "{JPN}まいった!$"

Route35_Text_CamperIvanAfter:
	.string "{JPN}ラジオの おんがくで やせいの\n"
	.string "{JPN}ポケモンの きぶんが かわるんだ$"

Route35_Text_CamperElliotSeen:
	.string "{JPN}かのじょに かっこいいところを\n"
	.string "{JPN}みせてやるぞ!$"

Route35_Text_CamperElliotBeaten:
	.string "{JPN}ぼくのために まけて\nくれたら よかったのに...$"
Route35_Text_CamperElliotAfter:
	.string "{JPN}かのじょの まえで\n"
	.string "{JPN}はずかしい おもいを\nしちゃったよ...$"
Route35_Text_PicnickerBrookeSeen:
	.string "{JPN}かれしが よわいから\n"
	.string "{JPN}あてに できないのよ$"

Route35_Text_PicnickerBrookeBeaten:
	.string "{JPN}あら! あなた つよいのね!$"

Route35_Text_PicnickerBrookeAfter:
	.string "{JPN}かれしより ポケモンの ほうが\n"
	.string "{JPN}あてに なるわ$"

Route35_Text_PicnickerKimSeen:
	.string "{JPN}ジムに いくの? わたしも!$"

Route35_Text_PicnickerKimBeaten:
	.string "{JPN}あら.かてなかった\nわ...$"
Route35_Text_PicnickerKimAfter:
	.string "{JPN}ジムバッジって きれいよね.\n"
	.string "{JPN}あつめてるの$"

Route35_Text_BirdKeeperBryanSeen:
	.string "{JPN}きみは どんな ボールを\nつかうんだい?$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "{JPN}うわあ! はやさが たりない!$"

Route35_Text_BirdKeeperBryanAfter:
	.string "{JPN}すぐに にげる ポケモンも いるよ.\p"
	.string "{JPN}ガンテツの スピードボールで\n"
	.string "{JPN}つかまえて みなよ.\p"
	.string "{JPN}フィラのみを みつけたら\n"
	.string "{JPN}ガンテツの ところに もっていくんだ.\p"
	.string "{JPN}とくべつな ボールに してくれるよ$"

Route35_Text_JugglerIrwinSeen:
	.string "{JPN}ぼくの うつくしい ボール\nさばきを みよ!$"

Route35_Text_JugglerIrwinBeaten:
	.string "{JPN}ふう! びりっと きた!$"

Route35_Text_JugglerIrwinAfter:
	.string "{JPN}じまんの ポケモンで\n"
	.string "{JPN}きみを おどろかそうと おもったが.\p"
	.string "{JPN}きみの うでまえに\nかんでんしたよ!$"

Route35_Text_BugCatcherArnieSeen:
	.string "{JPN}むしポケモンが いるなら\n"
	.string "{JPN}どこでも いくよ$"

Route35_Text_BugCatcherArnieBeaten:
	.string "{JPN}えー? こんなの\nまけるはずないのに...$"
Route35_Text_BugCatcherArnieAfter:
	.string "{JPN}しぜんこうえんの むしとり\n"
	.string "{JPN}たいかいで ぼくの コンパンが\nかったんだ$"

Route35_Text_BugCatcherArnieYanma:
	.string "{JPN}うわあ... あんなに\n"
	.string "{JPN}たくさんの ヤンヤンマ!\pすごくて うごけない\nよ.$"

Route35_Text_FirebreatherWaltSeen:
	.string "{JPN}かえんほうしゃの れんしゅうを\nしてるんだ$"

Route35_Text_FirebreatherWaltBeaten:
	.string "{JPN}いた! はなの さきを\nやけどしちゃった!$"

Route35_Text_FirebreatherWaltAfter:
	.string "{JPN}ラジオの ポケモンこうしんきょくが\n"
	.string "{JPN}やせいポケモンを おびきよせるんだ$"

Route35_Text_OfficerDirkSeen:
	.string "{JPN}よるは きけんが いっぱいだ!$"

Route35_Text_OfficerDirkBeaten:
	.string "{JPN}おっと!$"

Route35_Text_OfficerDirkAfter:
	.string "{JPN}よるの じかんも それなりに\n"
	.string "{JPN}たのしいものだがね.\p"
	.string "{JPN}でも やりすぎは だめだぞ?$"

Route35_Text_OfficerDirkTough:
	.string "{JPN}つよそうなポケモンだ\n"
	.string "{JPN}それならどこへいってもあんしんだ$"
Route35_Text_Sign:
	.string "{JPN}35ばん どうろ$"

Route35_Text_Sign2:
	.string "{JPN}しぜんこうえん ゲート$"
