# Intended for development purposes only, do not upload or use in production.
# See https://github.com/siteleaf/siteleaf-gem for documentation.
require 'rubygems'
require 'siteleaf'

run Siteleaf::Server.new(:site_id => ENV['SITE_ID'])
