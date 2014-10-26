---
layout: post
title: "Post with Figure"
description: "Examples and code for displaying images in posts."
category: articles
tags: [sample post, images, test]
---

This is a post that uses a `figure`. It stacks these images and places a nice little caption below if you fill out `figcaption`.

鉴于一些人对微软雅黑的排位产生异议，我不妨把上文的解决方案再延伸一步。事实是这样子的：

把微软雅黑放前面，会导致安装了微软雅黑字体的 Mac 用户不得不面对微软雅黑，而在 Mac 下比微软雅黑优雅得多的中文字体比比皆是；
把 Mac 下的字体放前面，也会对 Windows 用户造成差不多的困惑，毕竟微软雅黑是 Windows 平台下显示效果最好的字体（目前为止）；
1 和 2，哪一种出现的概率更大一些？我想这是一个不需要计算就能知道的答案吧？

但是——的确还有另外两个因素在纠结着：

不少 Windows 用户因为各种原因关闭了 ClearType，在此情形下微软雅黑将会惨不忍睹！但是 Mac 的字体也不是好的选择，真正的胜出者？猜对了，宋体。
绝大部分 Mac 下的黑体在 Windows 下模糊不清，而微软雅黑虽然丑但在 Mac 下至少能看。（间接体现了两个平台的字体渲染技术的差距）
所以在实践中，真正接近“万无一失”的方案需要考虑以下几点：

利用 UA 判断为不同的平台加载不一样的字体声明；
除非有特别的原因，否则尽量保持正文用宋体，标题和其他可以放大些的地方用微软雅黑（针对 Windows）；
Mac 下的冬青体效果极佳，但是该字体在 Mac OS X 10.6 以前是没有的，所以谨慎考虑你的用户群体，或者使用华文黑体系列做 fallback；

### Single Image Figure

<figure>
	<img src="http://farm9.staticflickr.com/8426/7758832526_cc8f681e48_c.jpg">
	<figcaption>Morning Fog Emerging From Trees by A Guy Taking Pictures, on Flickr</figcaption>
</figure>

```html
<figure>
	<img src="/images/image-filename-1.jpg">
	<figcaption>Caption describing these two images.</figcaption>
</figure>
```

```js
var aa = 1;
```

{% highlight ruby linenos %}
# Output "I love Ruby"
say = "I love Ruby"
puts say
{% endhighlight %}


{% highlight html linenos %}
<figure>
	<img src="/images/image-filename-1.jpg">
	<figcaption>Caption describing these two images.</figcaption>
</figure>
{% endhighlight %}
