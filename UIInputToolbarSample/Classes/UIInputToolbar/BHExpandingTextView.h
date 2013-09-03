/*
 *  UIExpandingTextView.h
 *
 *  Created by Brandon Hamilton on 2011/05/03.
 *  Copyright 2011 Brandon Hamilton.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#import <UIKit/UIKit.h>
#import "BHExpandingTextViewInternal.h"

@class BHExpandingTextView;

@protocol BHExpandingTextViewDelegate <NSObject>

@optional
- (BOOL)expandingTextViewShouldBeginEditing:(BHExpandingTextView *)expandingTextView;
- (BOOL)expandingTextViewShouldEndEditing:(BHExpandingTextView *)expandingTextView;

- (void)expandingTextViewDidBeginEditing:(BHExpandingTextView *)expandingTextView;
- (void)expandingTextViewDidEndEditing:(BHExpandingTextView *)expandingTextView;

- (BOOL)expandingTextView:(BHExpandingTextView *)expandingTextView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)expandingTextViewDidChange:(BHExpandingTextView *)expandingTextView;

- (void)expandingTextView:(BHExpandingTextView *)expandingTextView willChangeHeight:(float)height;
- (void)expandingTextView:(BHExpandingTextView *)expandingTextView didChangeHeight:(float)height;

- (void)expandingTextViewDidChangeSelection:(BHExpandingTextView *)expandingTextView;
- (BOOL)expandingTextViewShouldReturn:(BHExpandingTextView *)expandingTextView;
@end

@interface BHExpandingTextView : UIView <UITextViewDelegate>

@property (nonatomic, strong) UITextView *internalTextView;

@property (nonatomic, assign) NSUInteger maximumNumberOfLines;
@property (nonatomic, assign) NSUInteger minimumNumberOfLines;
@property (nonatomic, assign) BOOL animateHeightChange;

@property (nonatomic, weak) id<BHExpandingTextViewDelegate> delegate;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) UIFont *font;
@property (nonatomic, copy) UIColor *textColor;
@property (nonatomic) UITextAlignment textAlignment;
@property (nonatomic) NSRange selectedRange;
@property (nonatomic,getter=isEditable) BOOL editable;
@property (nonatomic) UIDataDetectorTypes dataDetectorTypes __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_3_0);
@property (nonatomic) UIReturnKeyType returnKeyType;
@property (nonatomic, strong) UIImageView *textViewBackgroundImage;
@property (nonatomic,copy) NSString *placeholder;
- (BOOL)hasText;
- (void)scrollRangeToVisible:(NSRange)range;
- (void)clearText;

@end
