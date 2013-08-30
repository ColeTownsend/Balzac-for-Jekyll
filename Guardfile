guard :shell, :all_on_start => true do
  watch(%r{^assets/sass/(.+\.s[ac]ss)$}) { `bundle exec sass --update --scss --style compressed --force --stop-on-error assets/sass/i.scss:assets/css/i.css` }
end

guard 'livereload' do
  watch(%r{.+\.(css|js|html)})
end
