//
//  UIView+JHDrawCategory.h
//  JHKit
//
//  Created by Lightech on 14-10-16.
//  Copyright (c) 2014年 Lightech. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (JHDrawCategory)

//画直线 - draw line in view.
- (void)jh_drawLineFromPoint:(CGPoint)fPoint
                     toPoint:(CGPoint)tPoint
                   lineColor:(UIColor *)color
                   lineWidth:(CGFloat)width;

//画虚线 - draw dash line in view.
//type: 0 - cube, 1 - round
- (void)jh_drawDashLineFromPoint:(CGPoint)fPoint
                         toPoint:(CGPoint)tPoint
                       lineColor:(UIColor *)color
                       lineWidth:(CGFloat)width
                       lineSpace:(CGFloat)space
                        lineType:(NSInteger)type;

//画五角星 - draw pentagram in view.
//rate: 0.3 ~ 1.1
- (void)jh_drawPentagram:(CGPoint)center
                  radius:(CGFloat)radius
                   color:(UIColor *)color
                    rate:(CGFloat)rate;
@end
