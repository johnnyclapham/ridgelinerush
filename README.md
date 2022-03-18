# ridgelinerush

Created for CSCI 437: Introduction to Game Design and Development

# Executive Summary

Endless runner game where the player must evade and do damage to an attacking dragon monster in order to beat the game. One level with obstacle generation for replayability. Hero climbs a mountainside-ridge, where they must do battle in order to survive.


# Team members:

Johnny Clapham

Evelyn Showalter

John Svoboda

Moses Alexander

# Game demo:

https://www.youtube.com/watch?v=qr5TzYzKBxo

# World description

Our dragon-slayer hero is dropped onto a hostile mountain ridge, where they must valiantly survive encounters against a plethora of extremely hostile dragons. For every dragon killed, our hero is rewarded with a special power-up champion status, which will enable them to teleport to the realm of the loot cave for a finite amount of time. This loot cave will have coins, additional weapons, and hazards that our hero must deal with in order to make it out alive. The final hero-score will depend on the number of dragons slain, the amount of coins retrieved, and the time survived.

# Characters

The dragon slayer is a nomad who wanders through the mountainside hunting for dangerous beasts to slay to make themself a legend. Their career comes to a climax when they reach the Ridgeline Mountains, which are crawling with dragons and have been the undoing of many other dragon slayers. They also have a greedy streak which causes them to compulsively hoard wealth, even if they have no use for it. The dragon slayer, blinded by dreams of glory, fights dragon after dragon, unwilling to stop even if it means their own demise. Their appearance is ragged and worn from years of fighting. Their face is cloaked such that it is hard to tell what their life was like before they started this long quest. Likes: glory, treasure, slaying dragons.

# File Structure, Set-up, compilation of code, generation of executable:

1. Initial state: you can see the file structure. We `cd` into the manually created debug directory

![](artifacts/setup/step1.png)

2. Second state: we type `cmake ..`  in order to populate the debug folder with necessary files to run our next command

![](artifacts/setup/step2.png)

3. Our final state: we type `make`  to generate our executable, which will be placed inside of the debug folder. Executables can be run via `./name.exe`

![](artifacts/setup/step3.png)

