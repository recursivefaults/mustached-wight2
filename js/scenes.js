Q.scene('level 1', function(stage) {
});

Q.scene('start', function(stage) {
    var container = stage.insert(new Q.UI.Container({
        x: Q.width/2, y: Q.height/2, fill: "rgba(0,0,0,0.5)"
    }));

    var button = container.insert(new Q.UI.Button({ x: 0, y: 0, fill: "#CCCCCC",
        label: "New Game" }));         
    var label = container.insert(new Q.UI.Text({x:10, y: -10 - button.p.h, 
        label: stage.options.label }));
    // When the button is clicked, clear all the stages
    // and restart the game.
    button.on("click",function() {
        console.log("Level 1 beginning");
        Q.clearStages();
        Q.stageScene('level 1');
    });

    // Expand the container to visibily fit it's contents
    container.fit(50);
});
