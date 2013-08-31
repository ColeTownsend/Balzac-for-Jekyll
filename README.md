# Balzac

![Balzac for Jekyll](http://cl.ly/Qdzo/Screen%20Shot%202013-08-05%20at%205.35.11%20PM.jpg)

![Balzac for Jekyll](http://cl.ly/Qdyh/Screen%20Shot%202013-08-05%20at%205.30.01%20PM.jpg)

This is forked from [Balzac for Jekyll](https://github.com/ColeTownsend/Balzac-for-Jekyll).

## Preview

[Preview the theme](http://balzac.siteleaf.net/)

## Download

[Download the theme](https://github.com/destroytoday/Balzac-for-Siteleaf/releases/tag/v1.0.1)

## Improvements over Jekyll theme

- greatly simplified template system, reducing to one for pages and one for posts (feature/no-feature/light-feature templates can be used through metadata `feature` and `dark`)
- refactored layout code to wrap content instead of including separate head/footer includes on every template
- removed head-dark include by adding `dark` metadata field
- extracted comments and sharing snippets to includes
- replaced complex excerpt template code with Siteleaf's `excerpt` variable
- removed Entypo icons from repo and replaced with links to Symbolset CDN
- removed all images (feature images should be uploaded to Siteleaf site to decouple from codebase)
- added Guardfile to watch SASS files and compile/compress when changed

## Original Features

- flexible, uses max-width for responsive goodness
- responsive drop down menu
- retina images using @2x
- post loop in the footer showing 3 latest posts
- custom portfolio page for case studies

## Basic Setup

1. [Download the theme](https://github.com/destroytoday/Balzac-for-Siteleaf/releases/tag/v1.0.1)
2. Upload theme to Siteleaf website.
3. Add [site metadata](#site-metadata)

## Advanced Setup (for local dev)

1. Fork this repo.
2. Open Terminal in the repo's directory.
2. Run `gem install bundler`.
3. Run `bundle install`.
4. Run `bundle exec siteleaf config YOUR_DOMAIN` with the domain of your Siteleaf website.
5. Run `bundle exec siteleaf server`.
6. Open `http://0.0.0.0:9292` in a browser to preview locally.
7. Run `bundle guard` to run Guard for SASS files.
8. Run `bundle exec siteleaf push theme` to upload any theme changes to Siteleaf.
9. Publish from Siteleaf.

## File Structure
 
``` bash
balzac-for-siteleaf/
├── _includes
|    ├── comments.html  // Disqus snippet
|    ├── share.html  // Twitter button snippet
├── _layouts
|    ├── default.html  // default layout
|    ├── page.html  // page/post layout
|    ├── posts.html  // posts layout
├── articles
|    ├── index.html  // template for Articles page
├── assets
|    ├── css  // compressed CSS styles
|    ├── js
|    |   ├── main.js  // jQuery plugins and settings
|    |   └── vendor  // all 3rd party scripts
|    └── sass // SASS styles
├── default.html  // global template
└── index.html  // homepage. lists 5 most recent posts
```

## Customization

### Site metadata

Add the following metadata to your Siteleaf site in the admin:

- name - name used in copyright footer
- email - email address used for contact
- description - site description used in HTML meta tag
- keywords - site keywords used in HTML meta tag
- disqus - Disqus shortname
- twitter - Twitter username
- symbolset - Symbolset ID
- repo - Github repo

### Top Navigation Links

Siteleaf will automatically use the top-level pages for the navigation links. Add a `hide_from_nav` metadata field to a page to hide it from the nav.

### Feature Images

To add a feature image for a given page or post, upload an asset, then create a metadata field `feature` with the absolute path to the image. For retina support, upload a second image with `@2x` inserted before the extension. (ex: `cool-photo@2x.jpg`. The retina.js script will handle the rest.

### Dark Images

To invert the header text to white instead of black for a given page/post, create a metadata field `dark` with the value `true`. This will add a slightly dark overlay to the image and whiten the text.

### Articles

This theme assumes that your posts are located in a page called `Articles` with the slug `articles`. If you change it to something like `blog`, be sure to do the following:

- rename the `/articles` directory to `/blog`
- edit `/index.html` and change `site.pages.articles` to `site.pages.blog`

### Comments

If you added a site metadata field for your Disqus shortname, you can include comments on any page by adding a metadata field `comments` with the value `true`.

## License

This is [MIT](LICENSE) with no added caveats, so feel free to use this Siteleaf theme on your site without linking back to me or using a disclaimer. 

If you'd like give the original designer, Cole Townsend, credit somewhere on your blog or tweet a shout out to
[@ctrunsthis](https://twitter.com/ctrunsthis), that would be pretty sweet.
