NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "{JPN}ピカチュウはしんかした\nポケモンなのよ\pウツギはかせのはっけんには\nびっくりしちゃった！\pポケモンしんかのけんきゅうで\nゆうめいなはかせなのよね\pはあ..\pわたしもあんなけんきゅうしゃに\nなりたいなあ..$"
NewBarkTown_House1_Text_Neighbor:
	.string "{JPN}むすめがウツギはかせの\nじょしゅになりたがってね\pほんとうにポケモンがすきなんだ！\pでもわたしもすきだがね！$"