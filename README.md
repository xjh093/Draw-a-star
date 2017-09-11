# Draw-a-star
画五角星

See the [GIF](http://www.jianshu.com/p/8fd2da39df76)

```
//画五角星 - draw pentagram in view.
//rate: 0.3 ~ 1.1
- (void)jh_drawPentagram:(CGPoint)center
                  radius:(CGFloat)radius
                   color:(UIColor *)color
                    rate:(CGFloat)rate;
                    
- (void)jh_drawPentagram:(CGPoint)center
                  radius:(CGFloat)radius
                   color:(UIColor *)color
                    rate:(CGFloat)rate
{
    CAShapeLayer* shapeLayer = [CAShapeLayer layer];
    shapeLayer.strokeColor = [UIColor clearColor].CGColor;
    shapeLayer.fillColor = [UIColor orangeColor].CGColor;
    if (color) {
        shapeLayer.fillColor = color.CGColor;
    }
    shapeLayer.path = ({
        UIBezierPath *path = [UIBezierPath bezierPath];
        
        //五角星最上面的点 & the top point of star
        CGPoint first  = CGPointMake(center.x, center.y-radius);
        
        [path moveToPoint:first];
        
        //点与点之间点夹角为2*M_PI/5.0,要隔一个点才连线
        CGFloat angle=4*M_PI/5.0;
        if (rate > 1.5) {
            rate = 1.5;
        }
        for (int i= 1; i <= 5; i++) {
            CGFloat x = center.x - sinf(i*angle)*radius;
            CGFloat y = center.y - cosf(i*angle)*radius;
            
            CGFloat midx = center.x - sinf(i*angle-2*M_PI/5.0)*radius*rate;
            CGFloat midy = center.y - cosf(i*angle-2*M_PI/5.0)*radius*rate;
            [path addQuadCurveToPoint:CGPointMake(x, y) controlPoint:CGPointMake(midx, midy)];
        }
        
        path.CGPath;
    });
    shapeLayer.lineWidth = 1.0f;
    shapeLayer.lineJoin = kCALineJoinRound;
    [self.layer addSublayer:shapeLayer];
}
```
