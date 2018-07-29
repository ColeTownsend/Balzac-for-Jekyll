#!/bin/sh

# Token generation
echo "cache_burst: $(date | md5)" > token.yml

bundle exec jekyll clean
bundle exec jekyll build --config _config.yml,token.yml

firebase deploy --non-interactive