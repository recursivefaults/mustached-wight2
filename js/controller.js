// Q.load can be called at any time to load additional assets
// assets that are already loaded will be skipped
Q.load('simple_map.tmx',

        // The callback will be triggered when everything is loaded
        function() {
            // Sprites sheets can be created manually
            //Q.sheet("tiles","tiles.png", { tilew: 32, tileh: 32 });

            // Or from a .json asset that defines sprite locations
            //Q.compileSheets("sprites.png","sprites.json");

            // Finally, call stageScene to run the game
        });
Q.stageScene("start");
