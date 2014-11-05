Q.Sprite.extend("Player", {
    init: function(p) {
        this._super(p, {
            color: 'red',
            h: 40,
            w: 40
        });
        //this.on("thing", function(event) {});
    },

    draw: function(context) {
        context.fillStyle = this.p.color;
        // Draw a filled rectangle centered at
        // 0,0 (i.e. from -w/2,-h2 to w/2, h/2)
        context.fillRect(-this.p.cx,
            -this.p.cy,
            this.p.w,
            this.p.h);
    },
});
