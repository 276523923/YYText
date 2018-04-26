//
//  YYLabel.h
//  YYText <https://github.com/ibireme/YYText>
//
//  Created by ibireme on 15/2/25.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<YYText/YYText.h>)
#import <YYText/YYTextParser.h>
#import <YYText/YYTextLayout.h>
#import <YYText/YYTextAttribute.h>
#else
#import "YYTextParser.h"
#import "YYTextLayout.h"
#import "YYTextAttribute.h"
#endif

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_INTERFACE_BUILDER

/**
 The YYLabel class implements a read-only text view.
 
 @discussion The API and behavior is similar to UILabel, but provides more features:
 
 * It supports asynchronous layout and rendering (to avoid blocking UI thread).
 * It extends the CoreText attributes to support more text effects.
 * It allows to add UIImage, UIView and CALayer as text attachments.
 * It allows to add 'highlight' link to some range of text to allow user interact with.
 * It allows to add container path and exclusion paths to control text container's shape.
 * It supports vertical form layout to display CJK text.
 
 See NSAttributedString+YYText.h for more convenience methods to set the attributes.
 See YYTextAttribute.h and YYTextLayout.h for more information.
 */

/**
 YYLabel类实现了只读文本视图。
 
 @discussion API和行为类似于UILabel，但提供了更多的特性:
 
 它支持异步布局和呈现(以避免阻塞UI线程)。
 *它扩展了CoreText属性以支持更多的文本效果。
 *它允许添加UIImage, UIView和CALayer作为文本附件。
 *它允许在某些文本范围内添加“高亮”链接，以允许用户与之交互。
 *它允许添加容器路径和排除路径来控制文本容器的形状。
 *它支持垂直表单布局来显示CJK文本。
 
 看到NSAttributedString + YYText。h为更方便的方法设置属性。
 看到YYTextAttribute。h和YYTextLayout。h的更多信息。
 */

@interface YYLabel : UIView <NSCoding>

#pragma mark - Accessing the Text Attributes
///=============================================================================
/// @name Accessing the Text Attributes
/// @name 访问文本属性。
///=============================================================================

/**
 The text displayed by the label. Default is nil.
 Set a new value to this property also replaces the text in `attributedText`.
 Get the value returns the plain text in `attributedText`.
 
 标签上显示的文本。默认是nil。
 为该属性设置一个新值也将替换“attributedText”中的文本。
 获取该值返回“attributedText”中的纯文本。
 */
@property (nullable, nonatomic, copy) NSString *text;

/**
 The font of the text. Default is 17-point system font.
 Set a new value to this property also causes the new font to be applied to the entire `attributedText`.
 Get the value returns the font at the head of `attributedText`.
 
 文本的字体。默认值为17点系统字体。
 为该属性设置一个新值也会使新字体应用于整个“attributedText”。
 获取该值返回“attributedText”头部的字体。
 */
@property (null_resettable, nonatomic, strong) UIFont *font;

/**
 The color of the text. Default is black.
 Set a new value to this property also causes the new color to be applied to the entire `attributedText`.
 Get the value returns the color at the head of `attributedText`.
 
 文本的颜色。默认是黑色的。
 为该属性设置一个新值也会使新颜色应用于整个“attributedText”。
 获取值返回“attributedText”头部的颜色。
 */
@property (null_resettable, nonatomic, strong) UIColor *textColor;

/**
 The shadow color of the text. Default is nil.
 Set a new value to this property also causes the shadow color to be applied to the entire `attributedText`.
 Get the value returns the shadow color at the head of `attributedText`.
 
 文本的阴影颜色。默认是nil。
 为该属性设置一个新值也会使阴影颜色应用于整个“attributedText”。
 获取该值返回“attributedText”头部的阴影颜色。
 */
@property (nullable, nonatomic, strong) UIColor *shadowColor;

/**
 The shadow offset of the text. Default is CGSizeZero.
 Set a new value to this property also causes the shadow offset to be applied to the entire `attributedText`.
 Get the value returns the shadow offset at the head of `attributedText`.
 
 文本的阴影偏移。默认是CGSizeZero。
 为该属性设置一个新值也会导致将影子偏移应用于整个“attributedText”。
 获取值返回“attributedText”头部的阴影偏移量。
 */
@property (nonatomic) CGSize shadowOffset;

/**
 The shadow blur of the text. Default is 0.
 Set a new value to this property also causes the shadow blur to be applied to the entire `attributedText`.
 Get the value returns the shadow blur at the head of `attributedText`.
 
 文本的阴影模糊。默认值为0。
 为该属性设置一个新值也会使阴影模糊应用于整个“attributedText”。
 获取该值返回“attributedText”头部的阴影模糊。
 */
@property (nonatomic) CGFloat shadowBlurRadius;

/**
 The technique to use for aligning the text. Default is NSTextAlignmentNatural.
 Set a new value to this property also causes the new alignment to be applied to the entire `attributedText`.
 Get the value returns the alignment at the head of `attributedText`.
 
 用于对齐文本的技术。默认是NSTextAlignmentNatural。
 为该属性设置一个新值也会使新对齐应用于整个“attributedText”。
 获取值返回“attributedText”头部的对齐方式。
 */
@property (nonatomic) NSTextAlignment textAlignment;

/**
 The text vertical aligmnent in container. Default is YYTextVerticalAlignmentCenter.
 
 该文本垂直于容器内。默认是YYTextVerticalAlignmentCenter。
 */
@property (nonatomic) YYTextVerticalAlignment textVerticalAlignment;

/**
 The styled text displayed by the label.
 Set a new value to this property also replaces the value of the `text`, `font`, `textColor`,
 `textAlignment` and other properties in label.
 
 @discussion It only support the attributes declared in CoreText and YYTextAttribute.
 See `NSAttributedString+YYText` for more convenience methods to set the attributes.
 
 标签显示的样式文本。
 为该属性设置一个新值也将替换“文本”、“字体”、“textColor”的值，
 标签上的“textali”和其他属性。
 
 它只支持在CoreText和YYTextAttribute中声明的属性。
 参见“NSAttributedString+YYText”以获得更方便的方法来设置属性。
 */
@property (nullable, nonatomic, copy) NSAttributedString *attributedText;

/**
 The technique to use for wrapping and truncating the label's text.
 Default is NSLineBreakByTruncatingTail.
 
 用于包装和截断标签文本的技术。
 默认是NSLineBreakByTruncatingTail。
 */
@property (nonatomic) NSLineBreakMode lineBreakMode;

/**
 The truncation token string used when text is truncated. Default is nil.
 When the value is nil, the label use "…" as default truncation token.
 
 截断文本时使用的截断令牌字符串。默认是nil。
 nil值时,标签用“…”作为默认截断令牌。
 */
@property (nullable, nonatomic, copy) NSAttributedString *truncationToken;

/**
 The maximum number of lines to use for rendering text. Default value is 1.
 0 means no limit.
 
 用于呈现文本的最大行数。默认值是1。
 0表示没有限制。
 */
@property (nonatomic) NSUInteger numberOfLines;

/**
 When `text` or `attributedText` is changed, the parser will be called to modify the text.
 It can be used to add code highlighting or emoticon replacement to text view. 
 The default value is nil.
 
 See `YYTextParser` protocol for more information.
 
 当“text”或“attributedText”被更改时，将调用解析器来修改文本。
 它可以用来在文本视图中添加代码高亮显示或emoticon替换。
 默认值为nil。
 
 有关更多信息，请参见“YYTextParser”协议。
 */
@property (nullable, nonatomic, strong) id<YYTextParser> textParser;

/**
 The current text layout in text view. It can be used to query the text layout information.
 Set a new value to this property also replaces most properties in this label, such as `text`,
 `color`, `attributedText`, `lineBreakMode`, `textContainerPath`, `exclusionPaths` and so on.
 
 文本视图中的当前文本布局。它可以用来查询文本布局信息。
 为该属性设置一个新值也将替换该标签中的大多数属性，如“text”，
 “color”，“attributedText”，“lineBreakMode”，“textContainerPath”，“exclusionPaths”等等。
 */
@property (nullable, nonatomic, strong) YYTextLayout *textLayout;


#pragma mark - Configuring the Text Container
///=============================================================================
/// @name Configuring the Text Container
/// @name 配置文本容器。
///=============================================================================

/**
 A UIBezierPath object that specifies the shape of the text frame. Default value is nil.
 
 一个UIBezierPath对象，它指定文本框的形状。默认值是零。
 */
@property (nullable, nonatomic, copy) UIBezierPath *textContainerPath;

/**
 An array of UIBezierPath objects representing the exclusion paths inside the
 receiver's bounding rectangle. Default value is nil.
 
 一个UIBezierPath对象数组，表示在其中的排除路径。
 接收机的边界矩形。默认值是零。
 */
@property (nullable, nonatomic, copy) NSArray<UIBezierPath *> *exclusionPaths;

/**
 The inset of the text container's layout area within the text view's content area.
 Default value is UIEdgeInsetsZero.
 
 文本容器在文本视图内容区域内的布局区域的inset。
 默认值是UIEdgeInsetsZero。
 */
@property (nonatomic) UIEdgeInsets textContainerInset;

/**
 Whether the receiver's layout orientation is vertical form. Default is NO.
 It may used to display CJK text.
 
 接收机的布局方向是否垂直。默认是NO。
 它可以用来显示CJK文本。
 */
@property (nonatomic, getter=isVerticalForm) BOOL verticalForm;

/**
 The text line position modifier used to modify the lines' position in layout.
 Default value is nil.
 See `YYTextLinePositionModifier` protocol for more information.
 
 文本行位置修饰符用于修改线条在布局中的位置。
 默认值是nil。
 有关更多信息,请参见“YYTextLinePositionModifier”协议。
 */
@property (nullable, nonatomic, copy) id<YYTextLinePositionModifier> linePositionModifier;

/**
 The debug option to display CoreText layout result.
 The default value is [YYTextDebugOption sharedDebugOption].
 
 显示CoreText布局结果的调试选项。
 默认值是[YYTextDebugOption sharedDebugOption]。
 */
@property (nullable, nonatomic, copy) YYTextDebugOption *debugOption;


#pragma mark - Getting the Layout Constraints
///=============================================================================
/// @name Getting the Layout Constraints
/// @name 获得布局约束。
///=============================================================================

/**
 The preferred maximum width (in points) for a multiline label.
 
 @discussion This property affects the size of the label when layout constraints 
     are applied to it. During layout, if the text extends beyond the width 
     specified by this property, the additional text is flowed to one or more new 
     lines, thereby increasing the height of the label. If the text is vertical 
     form, this value will match to text height.
 
 多行label的首选最大宽度(点)。
 
 当布局约束时，此属性会影响标签的大小。
 应用于它。在布局中，如果文本超出宽度。
 通过此属性指定，附加的文本将流到一个或多个新文本。
 线条，从而增加了标签的高度。如果文本是垂直的。
 表单，该值将匹配文本高度。
 */
@property (nonatomic) CGFloat preferredMaxLayoutWidth;


#pragma mark - Interacting with Text Data
///=============================================================================
/// @name Interacting with Text Data
/// @name 与文本数据交互。
///=============================================================================

/**
 When user tap the label, this action will be called (similar to tap gesture).
 The default value is nil.
 
 当用户点击label时，将调用此操作(类似于tap手势)。
 默认值为nil。
 */
@property (nullable, nonatomic, copy) YYTextAction textTapAction;

/**
 When user long press the label, this action will be called (similar to long press gesture).
 The default value is nil.
 
 当用户长按label时，这个动作将被调用(类似于长按手势)。
 默认值为nil。
 */
@property (nullable, nonatomic, copy) YYTextAction textLongPressAction;

/**
 When user tap the highlight range of text, this action will be called.
 The default value is nil.
 
 当用户点击高亮显示的label范围时，将调用此操作。
 默认值为nil。
 */
@property (nullable, nonatomic, copy) YYTextAction highlightTapAction;

/**
 When user long press the highlight range of text, this action will be called.
 The default value is nil.
 
 当用户长按高亮显示的文本范围时，将调用此操作。
 默认值为nil。
 */
@property (nullable, nonatomic, copy) YYTextAction highlightLongPressAction;


#pragma mark - Configuring the Display Mode
///=============================================================================
/// @name Configuring the Display Mode
/// @name 配置显示模式。
///=============================================================================

/**
 A Boolean value indicating whether the layout and rendering codes are running
 asynchronously on background threads. 
 
 The default value is `NO`.
 
 指示布局和呈现代码是否正在运行的布尔值。
 异步后台线程。
 
 默认值是“NO”。
 */
@property (nonatomic) BOOL displaysAsynchronously;

/**
 If the value is YES, and the layer is rendered asynchronously, then it will
 set label.layer.contents to nil before display. 
 
 The default value is `YES`.
 
 @discussion When the asynchronously display is enabled, the layer's content will
 be updated after the background render process finished. If the render process
 can not finished in a vsync time (1/60 second), the old content will be still kept
 for display. You may manually clear the content by set the layer.contents to nil 
 after you update the label's properties, or you can just set this property to YES.
 
 如果值是YES，并且该层是异步呈现的，那么它就会
 在渲染前设置 label.layer.contents 为nil。
 
 默认值是“YES”。
 
 当异步显示被启用时，该层的内容将会被激活。
 在后台渲染过程完成后更新。如果渲染过程
 无法在vsync(1/60秒)内完成，旧内容仍然保留
 显示。您可以通过设置层来手动清除内容。内容为nil
 在更新了标签的属性之后，或者您可以将该属性设置为YES。
 */
@property (nonatomic) BOOL clearContentsBeforeAsynchronouslyDisplay;

/**
 If the value is YES, and the layer is rendered asynchronously, then it will add 
 a fade animation on layer when the contents of layer changed. 
 
 The default value is `YES`.
 
 如果值是YES，并且该层是异步呈现的，那么它将添加一个渐变的动画
 当层的内容发生变化时
 
 默认值是“YES”。
 */
@property (nonatomic) BOOL fadeOnAsynchronouslyDisplay;

/**
 If the value is YES, then it will add a fade animation on layer when some range
 of text become highlighted. 
 
 The default value is `YES`.
 
 如果值是YES，那么它将在某个范围内添加一个渐变动画
 当 text 变成 highlighted 的时候显示
 
 默认值是“YES”。
 */
@property (nonatomic) BOOL fadeOnHighlight;

/**
 Ignore common properties (such as text, font, textColor, attributedText...) and
 only use "textLayout" to display content. 
 
 The default value is `NO`.
 
 @discussion If you control the label content only through "textLayout", then
 you may set this value to YES for higher performance.
 
 
 忽略公共属性(例如 text, font, textColor, attributedText...)
 只使用“textLayout”显示内容。
 
 默认值是“NO”。
 
 如果你只通过“textLayout”来控制标签内容
 您可以将这个值设置为YES以获得更高的性能。
 */
@property (nonatomic) BOOL ignoreCommonProperties;

/*
 Tips:
 
 1. If you only need a UILabel alternative to display rich text and receive link touch event, 
    you do not need to adjust the display mode properties.
 
 2. If you have performance issues, you may enable the asynchronous display mode
    by setting the `displaysAsynchronously` to YES.
 
 3. If you want to get the highest performance, you should do text layout with
    `YYTextLayout` class in background thread. Here's an example:
 
 1。如果您只需要一个UILabel替代来显示富文本和接收链接触摸事件，
 您不需要调整显示模式属性。
 
 2。如果您有性能问题，您可以启用异步显示模式。
 通过将“displaysasynchron”设置为YES。
 
 3所示。如果您想获得最高的性能，您应该在后台线程中使用“YYTextLayout”文本布局。
 这里有一个例子:
    
    YYLabel *label = [YYLabel new];
    label.displaysAsynchronously = YES;
    label.ignoreCommonProperties = YES;
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
 
        // Create attributed string.
        NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:@"Some Text"];
        text.yy_font = [UIFont systemFontOfSize:16];
        text.yy_color = [UIColor grayColor];
        [text yy_setColor:[UIColor redColor] range:NSMakeRange(0, 4)];
 
        // Create text container
        YYTextContainer *container = [YYTextContainer new];
        container.size = CGSizeMake(100, CGFLOAT_MAX);
        container.maximumNumberOfRows = 0;
        
        // Generate a text layout.
        YYTextLayout *layout = [YYTextLayout layoutWithContainer:container text:text];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            label.size = layout.textBoundingSize;
            label.textLayout = layout;
        });
    });
 
 */

@end


#else // TARGET_INTERFACE_BUILDER
IB_DESIGNABLE
@interface YYLabel : UIView <NSCoding>
@property (nullable, nonatomic, copy) IBInspectable NSString *text;
@property (null_resettable, nonatomic, strong) IBInspectable UIColor *textColor;
@property (nullable, nonatomic, strong) IBInspectable NSString *fontName_;
@property (nonatomic) IBInspectable CGFloat fontSize_;
@property (nonatomic) IBInspectable BOOL fontIsBold_;
@property (nonatomic) IBInspectable NSUInteger numberOfLines;
@property (nonatomic) IBInspectable NSInteger lineBreakMode;
@property (nonatomic) IBInspectable CGFloat preferredMaxLayoutWidth;
@property (nonatomic, getter=isVerticalForm) IBInspectable BOOL verticalForm;
@property (nonatomic) IBInspectable NSInteger textAlignment;
@property (nonatomic) IBInspectable NSInteger textVerticalAlignment;
@property (nullable, nonatomic, strong) IBInspectable UIColor *shadowColor;
@property (nonatomic) IBInspectable CGPoint shadowOffset;
@property (nonatomic) IBInspectable CGFloat shadowBlurRadius;
@property (nullable, nonatomic, copy) IBInspectable NSAttributedString *attributedText;
@property (nonatomic) IBInspectable CGFloat insetTop_;
@property (nonatomic) IBInspectable CGFloat insetBottom_;
@property (nonatomic) IBInspectable CGFloat insetLeft_;
@property (nonatomic) IBInspectable CGFloat insetRight_;
@property (nonatomic) IBInspectable BOOL debugEnabled_;

@property (null_resettable, nonatomic, strong) UIFont *font;
@property (nullable, nonatomic, copy) NSAttributedString *truncationToken;
@property (nullable, nonatomic, strong) id<YYTextParser> textParser;
@property (nullable, nonatomic, strong) YYTextLayout *textLayout;
@property (nullable, nonatomic, copy) UIBezierPath *textContainerPath;
@property (nullable, nonatomic, copy) NSArray<UIBezierPath*> *exclusionPaths;
@property (nonatomic) UIEdgeInsets textContainerInset;
@property (nullable, nonatomic, copy) id<YYTextLinePositionModifier> linePositionModifier;
@property (nonnull, nonatomic, copy) YYTextDebugOption *debugOption;
@property (nullable, nonatomic, copy) YYTextAction textTapAction;
@property (nullable, nonatomic, copy) YYTextAction textLongPressAction;
@property (nullable, nonatomic, copy) YYTextAction highlightTapAction;
@property (nullable, nonatomic, copy) YYTextAction highlightLongPressAction;
@property (nonatomic) BOOL displaysAsynchronously;
@property (nonatomic) BOOL clearContentsBeforeAsynchronouslyDisplay;
@property (nonatomic) BOOL fadeOnAsynchronouslyDisplay;
@property (nonatomic) BOOL fadeOnHighlight;
@property (nonatomic) BOOL ignoreCommonProperties;
@end
#endif // !TARGET_INTERFACE_BUILDER

NS_ASSUME_NONNULL_END
