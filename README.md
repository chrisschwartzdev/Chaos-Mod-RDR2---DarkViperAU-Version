<p align="center">
   <img src="https://i.imgur.com/uXrlAQW.png" alt="Chaos Mod RDR">
</p>

# Chaos Mod RDR2 with additional effects for DarkViperAU Livestream
This mod for **Red Dead Redemption 2** activates a random gameplay effect every 45 seconds. This effect can make it harder for you to play, help you, or just be neutral.

You can enable **Twitch Integration** and your viewers will be able to vote for effects.

You can find a list of effects **[here](https://docs.google.com/spreadsheets/d/1Z7dflg-n9VaXPnsqlzortFaUpkuy7XWrB9BGvJ8ilQk)**.

## Installation
- Install **[Script Hook RDR2](http://www.dev-c.com/rdr2/scripthookrdr2/)**.
- Download the latest mod version from the **[Releases page](https://github.com/darkviperau/Chaos-Mod-RDR2---DarkViperAU-Version/releases)** OR fetch the latest **[nightly build](https://nightly.link/darkviperau/Chaos-Mod-RDR2---DarkViperAU-Version/workflows/build-nightly.yaml/master?preview)**.
- Extract all files from the archive to the **game directory**. 
- Press **F7** in the game to *enable / disable* the mod. Mod is tested on game versions **1.0.1311.23** and **1.0.1436.28**.
## Twitch integration
- Open file **ChaosMod/config.json** and change param **twitch** from **false** to **true**.
- Launch the game, and wait for it to load into the single player
- Visit **[this link](http://127.0.0.1:9148/login)** and authorize access. 
- Re-enable mod with **F7**. Now your viewers can vote for effects in chat.
- If voting doesn't work and the **token** param is empty in **config.json** file, run the game as administrator.
## Twitch poll overlay
In **OBS** add new a **Browser source**. Enter these params:
<hr/>

**URL**: `http://127.0.0.1:9148/`

**Width**: `400`

**Height**: `220`

- [x] `Refresh browser when scene becomes active`
<hr/>

Press **Ctrl+E** when the source is selected and set position to `1490.0`, `105.0`

## Configuration
You can tweak some params in the **ChaosMod/config.json** file.

For example, **effects interval**, **voting time**, **effect status** (enabled/disabled), **effect duration**, **effect chance** (1-10) and **effect name**.

Don't forget to press **F7** in game when you have made changes.

## Controls
**F7** — toggle on/off the mod

**F8** — toggle off/on effects activation

**F10** — test any effect. **Arrows** to navigate, **Enter** to activate.

**F12** — instakill player character (useful when the game breaks)

## Development
### Setup RDR2 Script Hook SDK
1. Download the **[SDK](http://dev-c.com/rdr2/scripthookrdr2/)**
2. Extract it to `thirdparty/rdr2_sdk`

### Build Twitch Intergration Component
The twitch intergration component are in src/Twitch. To build it, do the following:
1. Download and install Node.js if you haven't https://nodejs.org/en/download/
2. Open the folder (src/Twitch) in Visual Studio Code
3. Open Terminal in VSCode, run command "npm install -g pkg" and "npm install -g typescript" to install required dependencies
4. After commands finished, open any .ts file in src/core, find any errored out module (e.g. config.ts). Hover on any errored out import module name(e.g. 'fs') and click on "Fix Problem" then "install <module name>". It will create "node_modules" and install all needed modules into it in /Twitch
5. Click "Run and Debug" on the side bar of VSCode, click on "Show all automatic debug configurations", then select "Node.js.." then "Run script: pkg". If everything's working, after some time you will find "ChaosModRDRTwitch.exe" in src/Twitch/bin/

## FAQ
**Q**: **How to change the time between activation of effects?**

**A**: Change the **interval** parameter in the config file.

**Q**: **My Twitch viewers can't vote for effects**

**A**: Check if the **token** parameter in the config file is not empty. If it's empty, restart the game as administrator and repeat steps in the **Twitch integration** guide.

**Q**: **The game crashes when I load a savegame or start a new game with Twitch enabled**

**A**: Press **F11**, the Twitch module will be temporarily disabled, and then reload your savegame or start new game after this.

**Q**: **The game is softlocked or broken**

**A**: Press **F12**, this hotkey will kill your character and it helps sometimes when the game is broken.

**Q**: **Characters are not spawning in the game**

**A**: The game has character limit of **150**. When you press **F7** to disable the mod, old spawned characters will be destroyed. Or leave a big town.

**Q**: **I stream on my separate PC, how do I get the OBS poll overlay to work there?**

**A**: Download the **[latest version](https://github.com/darkviperau/Chaos-Mod-RDR2---DarkViperAU-Version/releases)** of mod (at least **1.2.1**). Set the **local_ip** parameter in the config file to **false**. Find your **private IP**, for example in the Windows Network Settings. Then replace *127.0.0.1* with your **private IP** in the OBS browser source. It may look like **192.168.0.64:9148**.

**Q**: **My viewers are receiving the warning message "Your message was not sent because it is identical to the previous one you sent"**

**A**: Download the **[latest version](https://github.com/darkviperau/Chaos-Mod-RDR2---DarkViperAU-Version/releases)** of mod (at least **1.2.1**). Set the **max_options** parameter in the config file to **8**. Now the options in the poll will be **1-4** and **5-8**.


